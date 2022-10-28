/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:53:13 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/28 18:50:46 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_texture_x_offset(t_dda *ray)
{
	int	x_offset;

	if (ray->hzt_hit == TRUE)
		x_offset = (int)ray->hzt_x % 64;
	else
		x_offset = (int)ray->vrt_y % 64;
	if (x_offset < 0)
		x_offset = 0;
	return (x_offset);
}

int	ft_texture_y_offset(t_dda *ray, int y, int tex_height)
{
	int	y_offset;
	int	dist_from_top;

	dist_from_top = y + ((ray->strip_height / 2) - (HEIGHT / 2));
	y_offset = dist_from_top * ((double)tex_height / ray->strip_height);
	if (y_offset < 0)
		y_offset = 0;
	return (y_offset);
}

void	ft_init_textures(t_cub_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->tex[i].addr = mlx_get_data_addr(data->tex[i].img,
				&data->tex[i].bpp,
				&data->tex[i].line_len,
				&data->tex[i].endian);
		i++;
	}
}

void	ft_render_wall(t_cub_data *data, int top, int bottom, t_dda *ray)
{
	int	y;
	int	x;
	int	x_offset;
	int	colour;

	x = ray->id;
	y = -1;
	ft_init_textures(data);
	x_offset = ft_texture_x_offset(ray);
	while (++y < top)
		ft_put_pix_img(&data->img, x, y, data->ceilling);
	while (y < bottom)
	{
		colour = ft_pick_colour(data, ray, y, x_offset);
		ft_put_pix_img(&data->img, x, y, colour);
		y++;
	}
	while (y < HEIGHT)
	{
		ft_put_pix_img(&data->img, x, y, data->floor);
		y++;
	}
}
