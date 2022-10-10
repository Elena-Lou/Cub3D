/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/10 14:42:17 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_check(int key, t_cub_data *data)
{
	printf("key_check: player.x = %d player_y = %d\n", data->player.x,
		data->player.y);
	if (key == XK_Escape)
		ft_close_window(data);
	else if (key == XK_w)
		ft_move_forward(data);
	else if (key == XK_s)
		ft_move_backward(data);
	else if (key == XK_a)
		ft_strafe_left(data);
	else if (key == XK_d)
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
