/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:40:38 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/20 14:12:20 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_dir(t_dda *ray)
{
	if (ray->theta > 0 && ray->theta < WEST)
		ray->facing_up = FALSE;
	else
		ray->facing_up = TRUE;
	if (ray->theta < SOUTH || ray->theta > NORTH)
		ray->facing_left = FALSE;
	else
		ray->facing_left = TRUE;
}

double	ft_normalize_angle(double theta)
{
	if (theta < 0)
		theta += (2 * PI);
	return (theta);
}

void	ft_set_ray_data(t_cub_data *data)
{
	t_dda	ray[WIDTH];
	int		i;

	i = 0;
	ft_distance_to_projection_plane(&data->player);
	while (i < 1)
	{
		ray[i].id = i;
		ray[i].theta = data->player.pov - (FOV / 2);
		ft_cast_ray(&ray[i], data);
		i++;
		ray[i].theta += FOV / WIDTH;
	}
}
