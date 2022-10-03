/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:27:26 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/03 13:55:04 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_player_starting_position(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static void	ft_is_valid_map_pattern(t_cub_data *data, char **grid, int x, int y)
{
	static int	player_position = 0;

	if (grid[y][x] == '1' || grid[y][x] == ' ' || grid[y][x] == '\n')
		return ;
	else
	{
		if (ft_is_player_starting_position(grid[y][x]))
			player_position++;
		if (player_position > 1)
			ft_exit_check_grid(data, "Redefining player spawn position.\n");
		if (y == 0 || grid[y + 1] == NULL)
			ft_exit_check_grid(data, "Map is not closed with walls.\n");
		if (x == 0 || grid[y][x + 1] == '\n' || grid[y][x + 1] == '\0')
			ft_exit_check_grid(data, "Map is not closed with walls.\n");
		if (grid[y - 1][x] == ' ' || grid[y + 1][x] == ' '
			|| grid[y][x - 1] == ' ' || grid[y][x + 1] == ' ')
			ft_exit_check_grid(data, "Map is not closed with walls.\n");
	}
}

static int	ft_is_valid_map_char(char c)
{
	if (ft_is_player_starting_position(c))
		return (1);
	if (c == '1')
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int	ft_check_map_grid(t_cub_data *data, char **grid)
{
	int	player;
	int	x;
	int	y;

	y = 0;
	player = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (ft_is_player_starting_position(grid[y][x]))
				player++;
			if (ft_is_valid_map_char(grid[y][x]))
				ft_is_valid_map_pattern(data, grid, x, y);
			else
				return (1);
			x++;
		}
		y++;
	}
	if (player == 0)
		ft_exit_check_grid(data, "No spawn for player.");
	return (0);
}
