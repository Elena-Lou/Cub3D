/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:42:27 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/10 10:07:50 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_minimap_borders(t_cub_data *data, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < 155)
	{
		x = -1;
		while (++x <= 205)
		{
			if (x < 5 || x > 200 || y < 5 || y > 150)
				ft_put_pix_img(&data->minimap, x, y, colour);
		}
		y++;
	}
}

void	ft_create_minimap(t_cub_data *data)
{
	char	minimap[42][32];

	printf("player x = %i\nplayer y = %i\n", data->player.x, data->player.y);
	(void)minimap;
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr, 205, 155);
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	ft_render_minimap_borders(data, 0x2874A6);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->minimap.mlx_img, 5, 640);
	mlx_destroy_image(data->mlx_ptr, data->minimap.mlx_img);
}
