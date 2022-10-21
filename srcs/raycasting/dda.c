/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:40:38 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/20 15:05:59 by elouisia         ###   ########.fr       */
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
		ray[i].theta = data->player.pov + atan((i - WIDTH / 2)
				/ data->player.dist_pp);
		ft_cast_ray(data, &ray[i]);
		ft_wall_projection(data, &ray[i]);
		i++;
	}
}
