/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/17 15:23:23 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_move(t_cub_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += ft_move_forward(data);
	if (data->player.move_y == -1)
		moved += ft_move_backward(data);
	if (data->player.move_x == -1)
		moved += ft_strafe_left(data);
	if (data->player.move_x == 1)
		moved += ft_strafe_right(data);
	if (data->player.rotate == -1)
		moved += ft_rotate_right(data);
	if (data->player.rotate == 1)
		moved += ft_rotate_left(data);
	return (moved);
}

int	ft_key_release_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		ft_close_window(data);
	if (data->player.move_y == 1 && key == XK_w)
		data->player.move_y = 0;
	if (data->player.move_y == -1 && key == XK_s)
		data->player.move_y = 0;
	if (data->player.move_x == -1 && key == XK_a)
		data->player.move_x += 1;
	if (data->player.move_x == 1 && key == XK_d)
		data->player.move_x -= 1;
	if (data->player.rotate == 1 && key == LEFT_ARROW)
		data->player.rotate = 0;
	if (data->player.rotate == -1 && key == RIGHT_ARROW)
		data->player.rotate = 0;
	return (0);
}

int	ft_key_press_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		ft_close_window(data);
	if (key == XK_w)
		data->player.move_y = 1;
	else if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	else if (key == LEFT_ARROW)
		data->player.rotate = 1;
	else if (key == RIGHT_ARROW)
		data->player.rotate = -1;
	return (0);
}
