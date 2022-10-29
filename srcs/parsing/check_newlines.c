/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:23:09 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 17:40:47 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_contains_newline(char **grid, int x, int y)
{
	if (grid[y][x] == '\n')
	{
		x = 0;
		y++;
		while (grid[y] && grid[y][x])
		{
			if (ft_is_player_starting_position(grid[y][x])
					|| grid[y][x] == '0' || grid[y][x] == '1')
				return (0);
			else if (grid[y][x] == '\n')
				return (1);
			x++;
		}
	}
	return (0);
}
