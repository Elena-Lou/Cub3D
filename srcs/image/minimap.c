/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:42:27 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/02 15:36:50 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_minimap(t_cub_data *data, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x <= 200)
		{
			ft_put_pix_img(&data->minimap, x, y, colour);
			x++;
		}
		y++;
	}
	while (y < 141)
		y++;
	while (y >= 140 && y <= 150)
	{
		x = 0;
		while (x <= 200)
		{
			ft_put_pix_img(&data->minimap, x, y, colour);
			x++;
		}
		y++;
	}
}

void	ft_create_minimap(t_cub_data *data)
{
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr, 200, 150);
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	ft_render_minimap(data, 0x2874A6);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->minimap.mlx_img, 10, 600);
	mlx_destroy_image(data->mlx_ptr, data->minimap.mlx_img);
}
