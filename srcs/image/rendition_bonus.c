/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendition_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:02:13 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:03:30 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_line(t_cub_data *data, double angle, double len, int colour)
{
	double	distance;
	double	coord_x;
	double	coord_y;

	distance = 0;
	while (distance < len)
	{
		coord_x = data->player.x + distance * cos(angle);
		coord_y = data->player.y + distance * sin(angle);
		ft_put_pix_img(&data->img, coord_x, coord_y, colour);
		distance++;
	}
}

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

int	ft_render_img(t_cub_data *data)
{
	int	moved;

	moved = 0;
	ft_move(data, &moved);
	if (moved)
	{
		if (data->img.mlx_img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		if (data->minimap.mlx_img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->minimap.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		if (!data->img.mlx_img)
			return (1);
		ft_render_minimap(data);
		ft_set_ray_data(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, 0, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->minimap.mlx_img, 5, 640);
	}
	return (0);
}
