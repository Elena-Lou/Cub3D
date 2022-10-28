/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:53:59 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/28 14:56:19 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_pick_colour(t_cub_data *data, t_dda *ray, int y_offset, int x_offset)
{
	unsigned int	colour;
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
		index = (data->tex[NO].line_len * y_offset) + (x_offset * data->tex[NO].bpp / 8);
		colour = ((int *)data->tex[NO].addr)[index / 4];
	}
	else if (ray->hzt_hit == TRUE && ray->facing_up == FALSE)
	{
		if (x_offset >= data->tex[SO].width)
			x_offset = data->tex[SO].width - 1;
		if (y_offset >= data->tex[SO].height)
			y_offset = data->tex[SO].height - 1;
		index = (data->tex[SO].line_len * y_offset) + (x_offset * data->tex[SO].bpp / 8);
		colour = ((int *)data->tex[SO].addr)[index / 4];
	}
	else if (ray->vrt_hit == TRUE && ray->facing_left == TRUE)
	{		
		if (x_offset >= data->tex[EA].width)
			x_offset = data->tex[EA].width - 1;
		if (y_offset >= data->tex[EA].height)
			y_offset = data->tex[EA].height - 1;
		index = (data->tex[EA].line_len * y_offset) + (x_offset * data->tex[EA].bpp / 8);
		colour = ((int *)data->tex[EA].addr)[index / 4];
	}
	else
	{
		if (x_offset >= data->tex[WE].width)
			x_offset = data->tex[WE].width - 1;
		if (y_offset >= data->tex[WE].height)
			y_offset = data->tex[WE].height - 1;
		index = (data->tex[WE].line_len * y_offset) + (x_offset * data->tex[WE].bpp / 8);
		colour = ((int *)data->tex[WE].addr)[index / 4];
	}
	return (colour);
}
