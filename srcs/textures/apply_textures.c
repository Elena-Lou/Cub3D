/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:53:13 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/27 19:00:12 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pick_colour(t_cub_data *data, t_dda *ray, int y_offset, int x_offset)
{
	// unsigned int	colour;
	int				index;

	if (x_offset < 0)
		x_offset = 0;

	if (y_offset < 0)
		y_offset = 0;

	if (ray->hzt_hit == TRUE && ray->facing_up == TRUE)
	{
		if (x_offset >= data->tex[NO].width)
			x_offset = data->tex[NO].width - 1;
		if (y_offset >= data->tex[NO].height)
			y_offset = data->tex[NO].height - 1;
		// printf("y_offset %d, x_offset %d\n", y_offset, x_offset);
		index = data->tex[NO].addr[data->tex[NO].line_len * y_offset + x_offset * data->tex[NO].bpp / 8];
		// printf("A : %d, B : %d\n", data->tex[NO].line_len * y_offset, data->tex[NO].bpp);
		// printf("index = %d\n", (unsigned int)index);
		// colour = data->tex[NO].addr[(unsigned int)index / 4];
	}
	else if (ray->hzt_hit == TRUE && ray->facing_up == FALSE)
	{
		if (x_offset >= data->tex[SO].width)
			x_offset = data->tex[SO].width - 1;
		if (y_offset >= data->tex[SO].height)
			y_offset = data->tex[SO].height - 1;
		index = data->tex[SO].addr[(data->tex[SO].line_len * y_offset) + (x_offset * data->tex[SO].bpp / 8)];
		// colour = ((int *)data->tex[SO].addr)[index / 4];
	}
	else if (ray->vrt_hit == TRUE && ray->facing_left == TRUE)
	{		
		if (x_offset >= data->tex[EA].width)
			x_offset = data->tex[EA].width - 1;
		if (y_offset >= data->tex[EA].height)
			y_offset = data->tex[EA].height - 1;
		index = data->tex[EA].addr[(data->tex[EA].line_len * y_offset) + (x_offset * data->tex[EA].bpp / 8)];
		// colour = ((int *)data->tex[EA].addr)[index / 4];

	}
	else
	{
		if (x_offset >= data->tex[WE].width)
			x_offset = data->tex[WE].width - 1;
		if (y_offset >= data->tex[WE].height)
			y_offset = data->tex[WE].height - 1;
		index = data->tex[WE].addr[(data->tex[WE].line_len * y_offset) + (x_offset * data->tex[WE].bpp / 8)];
		// colour = ((int *)data->tex[WE].addr)[index / 4];
	}
	return (index);
}

int	ft_texture_x_offset(t_dda *ray)
{
	int	x_offset;

	if (ray->hzt_hit == TRUE)
		x_offset = (int)ray->hzt_x % 64;
	else
		x_offset = (int)ray->vrt_y % 64;
	return (x_offset);
}

int	ft_texture_y_offset(t_dda *ray, int y)
{
	int	y_offset;
	int	dist_from_top;

	dist_from_top = y + ((ray->strip_height / 2) - (HEIGHT / 2));
	y_offset = dist_from_top * ((double)TEX_SIZE / ray->strip_height);
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
	int	y_offset;
	unsigned int colour;

	x = ray->id;
	y = -1;
	ft_init_textures(data);
	x_offset = ft_texture_x_offset(ray);
	while (++y < top)
		ft_put_pix_img(&data->img, x, y, data->ceilling);
	while (y < bottom)
	{
		y_offset = ft_texture_y_offset(ray, y);
		colour = ft_pick_colour(data, ray, y_offset, x_offset);
		ft_put_pix_img(&data->img, x, y, colour);
		y++;
	}
	while (y < HEIGHT)
	{
		ft_put_pix_img(&data->img, x, y, data->floor);
		y++;
	}
}
