/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:02:05 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:03:32 by aweaver          ###   ########.fr       */
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

void	ft_set_ray_data(t_cub_data *data)
{
	t_dda	ray[WIDTH];
	int		i;

	i = 0;
	ft_distance_to_projection_plane(&data->player);
	while (i < WIDTH)
	{
		ray[i].id = i;
		ray[i].theta = data->player.pov + atan(((double)i - (double)WIDTH / 2.0)
				/ data->player.dist_pp);
		ray[i].theta = ft_normalise_angle(ray[i].theta);
		ft_cast_ray(data, &ray[i]);
		ft_wall_projection(data, &ray[i]);
		i++;
	}
}
