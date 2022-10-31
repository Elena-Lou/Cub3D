/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_colours_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:46 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:29:53 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pick_colour(t_cub_data *data, t_dda *ray, int y, int x_offset)
{
	int	y_offset;
	int	colour;
	int	index;
	int	wall_orientation;

	if (ray->hzt_hit == TRUE && ray->facing_up == TRUE)
		wall_orientation = NO;
	else if (ray->hzt_hit == TRUE && ray->facing_up == FALSE)
		wall_orientation = SO;
	else if (ray->vrt_hit == TRUE && ray->facing_left == TRUE)
		wall_orientation = EA;
	else
		wall_orientation = WE;
	y_offset = ft_texture_y_offset(ray, y, data->tex[wall_orientation].height);
	x_offset = x_offset * data->tex[wall_orientation].width / 64;
	if (x_offset >= data->tex[wall_orientation].width)
		x_offset = data->tex[wall_orientation].width - 1;
	if (y_offset >= data->tex[wall_orientation].height)
		y_offset = data->tex[wall_orientation].height - 1;
	index = ((data->tex[wall_orientation].line_len * y_offset)
			+ (x_offset * data->tex[wall_orientation].bpp / 8));
	colour = ((int *)data->tex[wall_orientation].addr)[index / 4];
	return (colour);
}
