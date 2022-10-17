/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:44:16 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/17 14:51:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_valid_move(t_cub_data *data, int x, int y)
{
	int	new_tile_x;
	int	new_tile_y;

	new_tile_x = x >> 6;
	new_tile_y = y >> 6;
	if (new_tile_x < 0 || new_tile_y < 0 || new_tile_x > data->map_width
		|| new_tile_y > data->map_height)
		return (0);
	if (data->grid[new_tile_y][new_tile_x] == '1'
		|| data->grid[new_tile_y][new_tile_x] == ' '
		|| data->grid[new_tile_y][new_tile_x] == '\0')
		return (0);
	return (1);
}

int	ft_strafe_left(t_cub_data *data)
{
	int	moved;
	int	x;
	int	y;

	moved = 0;
	x = 0.5 + data->player.x - (1.0 * cos(data->player.pov + SOUTH));
	y = 0.5 + data->player.y - (1.0 * sin(data->player.pov + SOUTH));
	if (ft_is_valid_move(data, x, data->player.y))
	{
		data->player.x = x;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.x, y))
	{
		data->player.y = y;
		moved = 1;
	}
	return (moved);
}

int	ft_strafe_right(t_cub_data *data)
{
	int	moved;
	int	x;
	int	y;

	moved = 0;
	x = 0.5 + data->player.x + (1.0 * cos(data->player.pov + SOUTH));
	y = 0.5 + data->player.y + (1.0 * sin(data->player.pov + SOUTH));
	if (ft_is_valid_move(data, x, data->player.y))
	{
		data->player.x = x;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.x, y))
	{
		data->player.y = y;
		moved = 1;
	}
	return (moved);
}

int	ft_move_backward(t_cub_data *data)
{
	int	moved;
	int	x;
	int	y;

	moved = 0;
	x = 0.5 + data->player.x - (1.0 * cos(data->player.pov));
	y = 0.5 + data->player.y - (1.0 * sin(data->player.pov));
	if (ft_is_valid_move(data, x, data->player.y))
	{
		data->player.x = x;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.x, y))
	{
		data->player.y = y;
		moved = 1;
	}
	return (moved);
}

int	ft_move_forward(t_cub_data *data)
{
	int	moved;
	int	x;
	int	y;

	moved = 0;
	x = 0.5 + data->player.x + (1.0 * cos(data->player.pov));
	y = 0.5 + data->player.y + (1.0 * sin(data->player.pov));
	if (ft_is_valid_move(data, x, data->player.y))
	{
		data->player.x = x;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.x, y))
	{
		data->player.y = y;
		moved = 1;
	}
	return (moved);
}
