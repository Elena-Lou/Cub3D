/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:44:16 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/07 14:12:50 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_valid_move(t_cub_data *data, int x, int y)
{
	int	map_height;
	int	map_width;
	int	new_tile_x;
	int	new_tile_y;

	map_height = ft_strptr_len(data->grid);
	map_width = ft_strlen_int(*data->grid);
	new_tile_x = x >> 6;
	new_tile_y = y >> 6;
	if (new_tile_x < 0 || new_tile_y < 0 || new_tile_x > map_width
		|| new_tile_y > map_height)
		return (0);
	if (data->grid[new_tile_y][new_tile_x] == '1'
		|| data->grid[new_tile_y][new_tile_x] == ' '
		|| data->grid[new_tile_y][new_tile_x] == '\0')
		return (0);
	return (1);
}

int	ft_strafe_left(t_cub_data *data)
{
	int	x;

	x = data->player.x - (data->player.dir_x * 4);
	if (ft_is_valid_move(data, x, data->player.y))
		data->player.x = x;
	return (0);
}

int	ft_strafe_right(t_cub_data *data)
{
	int	x;

	x = data->player.x + (data->player.dir_x * 4);
	if (ft_is_valid_move(data, x, data->player.y))
		data->player.x = x;
	return (0);
}

int	ft_move_backward(t_cub_data *data)
{
	int	y;

	y = data->player.y - (data->player.dir_y * 4);
	if (ft_is_valid_move(data, data->player.x, y))
		data->player.y = y;
	return (0);
}

int	ft_move_forward(t_cub_data *data)
{
	int	y;

	y = data->player.y + (data->player.dir_y * 4);
	if (ft_is_valid_move(data, data->player.x, y))
		data->player.y = y;
	return (0);
}
