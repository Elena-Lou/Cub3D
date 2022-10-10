/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:32:52 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/10 16:28:47 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_background(t_cub_data *data, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x % 64 == 0 || y % 64 == 0)
				ft_put_pix_img(&data->img, x, y, 0x000000);
			else if (data->grid[y >> 6][x >> 6] == '1')
				ft_put_pix_img(&data->img, x, y, 0x12354d);
			else
				ft_put_pix_img(&data->img, x, y, colour);
			x++;
		}
		y++;
	}
}

void	ft_render_player(t_cub_data *data, int colour)
{
	int	y;
	int	x;

	y = data->player.y;
	while (y < data->player.y + 8)
	{
		x = data->player.x;
		while (x < data->player.x + 8)
		{
			if (x < WIDTH && y < HEIGHT)
				ft_put_pix_img(&data->img, x, y, colour);
			x++;
		}
		y++;
	}
}

void	ft_init_player(t_cub_data *data)
{
	//data->player.x = WIDTH / 2;
	//data->player.y = HEIGHT / 2;
	(void)data;
}

int	ft_render_img(t_cub_data *data)
{
	ft_render_background(data, 0xA9A9A9);
	ft_render_player(data, 0x8E1600);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	ft_create_minimap(data);
	return (0);
}
