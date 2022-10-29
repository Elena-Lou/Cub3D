/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:53:59 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/28 15:05:43 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pick_colour(t_cub_data *data, t_dda *ray, int y_offset, int x_offset)
{
	int	colour;
	int	index;
	int	wall_orientation;

	if (x_offset < 0)
		x_offset = 0;
	if (y_offset < 0)
		y_offset = 0;
	if (ray->hzt_hit == TRUE && ray->facing_up == TRUE)
		wall_orientation = NO;
	else if (ray->hzt_hit == TRUE && ray->facing_up == FALSE)
		wall_orientation = SO;
	else if (ray->vrt_hit == TRUE && ray->facing_left == TRUE)
		wall_orientation = EA;
	else
		wall_orientation = WE;
	if (x_offset >= data->tex[wall_orientation].width)
		x_offset = data->tex[wall_orientation].width - 1;
	if (y_offset >= data->tex[wall_orientation].height)
		y_offset = data->tex[wall_orientation].height - 1;
	index = (data->tex[wall_orientation].line_len * y_offset)
		+ (x_offset * data->tex[wall_orientation].bpp / 8);
	colour = ((int *)data->tex[wall_orientation].addr)[index / 4];
	return (colour);
}
