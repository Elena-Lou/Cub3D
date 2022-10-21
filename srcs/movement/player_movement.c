/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:44:16 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/21 11:37:38 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_valid_move(t_cub_data *data, int new_tile_x, int new_tile_y)
{
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
	int		moved;
	double	x;
	double	y;

	moved = 0;
	x = data->player.x - (1.0 * cos(data->player.pov + SOUTH));
	y = data->player.y - (1.0 * sin(data->player.pov + SOUTH));
	if (ft_is_valid_move(data, (int)x >> 6, data->player.tile_y))
	{
		data->player.x = x;
		data->player.tile_x = (int)x >> 6;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.tile_x, (int)y >> 6))
	{
		data->player.y = y;
		data->player.tile_y = (int)y >> 6;
		moved = 1;
	}
	return (moved);
}

int	ft_strafe_right(t_cub_data *data)
{
	int		moved;
	double	x;
	double	y;

	moved = 0;
	x = data->player.x + (1.0 * cos(data->player.pov + SOUTH));
	y = data->player.y + (1.0 * sin(data->player.pov + SOUTH));
	if (ft_is_valid_move(data, (int)x >> 6, data->player.tile_y))
	{
		data->player.x = x;
		data->player.tile_x = (int)x >> 6;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.tile_x, (int)y >> 6))
	{
		data->player.y = y;
		data->player.tile_y = (int)y >> 6;
		moved = 1;
	}
	return (moved);
}

int	ft_move_backward(t_cub_data *data)
{
	int		moved;
	double	x;
	double	y;

	moved = 0;
	x = data->player.x - (1.0 * cos(data->player.pov));
	y = data->player.y - (1.0 * sin(data->player.pov));
	if (ft_is_valid_move(data, (int)x >> 6, data->player.tile_y))
	{
		data->player.x = x;
		data->player.tile_x = (int)x >> 6;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.tile_x, (int)y >> 6))
	{
		data->player.y = y;
		data->player.tile_y = (int)y >> 6;
		moved = 1;
	}
	return (moved);
}

int	ft_move_forward(t_cub_data *data)
{
	int		moved;
	double	x;
	double	y;

	moved = 0;
	x = data->player.x + (1.0 * cos(data->player.pov));
	y = data->player.y + (1.0 * sin(data->player.pov));
	if (ft_is_valid_move(data, (int)x >> 6, data->player.tile_y))
	{
		data->player.x = x;
		data->player.tile_x = (int)x >> 6;
		moved = 1;
	}
	if (ft_is_valid_move(data, data->player.tile_x, (int)y >> 6))
	{
		data->player.y = y;
		data->player.tile_y = (int)y >> 6;
		moved = 1;
	}
	return (moved);
}
