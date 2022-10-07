/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/07 18:00:47 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		ft_close_window(data);
	else if (key == XK_w && data->player.y > 0)
		ft_move_forward(data);
	else if (key == XK_s && data->player.y < HEIGHT - 10)
		ft_move_backward(data);
	else if (key == XK_a && data->player.x > 0)
		ft_strafe_left(data);
	else if (key == XK_d && data->player.x < WIDTH - 10)
		ft_strafe_right(data);
	else if (key == LEFT_ARROW)
		ft_rotate_left(data);
	else if (key == RIGHT_ARROW)
		ft_rotate_right(data);
	else
		printf("%d\n", key);
	ft_render_img(data);
	return (0);
}
