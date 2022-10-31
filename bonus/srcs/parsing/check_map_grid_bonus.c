/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_grid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:39:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/31 10:39:36 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_player_starting_position(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

static void	ft_is_valid_map_pattern(t_cub_data *data, char **grid, int x, int y)
{
	if (grid[y][x] == '1' || grid[y][x] == ' ' || grid[y][x] == '\n')
		return ;
	else if (grid[y][x] == '0' || ft_is_player_starting_position(grid[y][x]))
	{
		if (y == 0 || grid[y + 1] == NULL)
			ft_exit_check_grid(data, "Map is not closed with walls.\n");
		if (x == 0 || grid[y][x + 1] == '\n' || grid[y][x + 1] == '\0')
			ft_exit_check_grid(data, "Map is not closed with walls.\n");
		if (ft_is_void(grid[y - 1][x]) || ft_is_void(grid[y + 1][x])
				|| ft_is_void(grid[y][x - 1]) || ft_is_void(grid[y][x + 1]))
			ft_exit_check_grid(data, "Map is not closed with walls!\n");
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

void	ft_set_player_spawn(t_cub_data *data, int x, int y, int *spawn_counts)
{
	ft_is_valid_map_pattern(data, data->grid, x, y);
	*spawn_counts += 1;
	ft_update_player_tile(data, x, y);
	data->player.pov = NORTH;
	data->player.dir_y = -1;
	data->player.dir_x = 0;
	if (data->grid[y][x] == 'S')
	{
		data->player.pov = SOUTH;
		data->player.dir_y = 1;
		data->player.dir_x = 0;
	}
	else if (data->grid[y][x] == 'E')
	{
		data->player.pov = EAST;
		data->player.dir_y = 0;
		data->player.dir_x = 1;
	}
	else if (data->grid[y][x] == 'W')
	{
		data->player.pov = WEST;
		data->player.dir_y = 0;
		data->player.dir_y = 0;
		data->player.dir_x = -1;
	}
}

void	ft_check_map_grid(t_cub_data *data, char **grid)
{
	int	player;
	int	x;
	int	y;

	y = -1;
	player = 0;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (ft_map_contains_newline(grid, x, y))
				ft_exit_check_grid(data, "Map contains invalid data.");
			if (ft_is_player_starting_position(grid[y][x]))
				ft_set_player_spawn(data, x, y, &player);
			if (ft_is_valid_map_char(grid[y][x]))
				ft_is_valid_map_pattern(data, grid, x, y);
			else
				ft_exit_check_grid(data, "Map contains wrong data.");
		}
	}
	if (player < 1)
		ft_exit_check_grid(data, "No spawn for player.");
	if (player > 1)
		ft_exit_check_grid(data, "Redefining player spawn position.");
}
