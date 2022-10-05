/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/05 12:08:25 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		ft_close_window(data);
	else if (key == XK_w && data->player.y > 0)
		data->player.y -= 5;
	else if (key == XK_s && data->player.y < HEIGHT - 10)
		data->player.y += 5;
	else if (key == XK_a && data->player.x > 0)
		data->player.x -= 5;
	else if (key == XK_d && data->player.x < WIDTH - 10)
		data->player.x += 5;
	else
		printf("%d\n", key);
	printf("data->player.x = %i\n", data->player.x);
	printf("data->player.y = %i\n", data->player.y);
	ft_render_img(data);
	return (0);
}
