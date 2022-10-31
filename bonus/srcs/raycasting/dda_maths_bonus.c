/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_maths_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:43 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:30:06 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_closest_distance(t_dda *ray)
{
	if (ray->vrt_dist < ray->hzt_dist)
	{
		ray->distance = ray->vrt_dist;
		ray->hzt_hit = FALSE;
	}
	else if (ray->hzt_dist == ray->vrt_dist)
	{
		ray->distance = ray->hzt_dist;
		ray->vrt_hit = FALSE;
	}
	else
	{
		ray->distance = ray->hzt_dist;
		ray->vrt_hit = FALSE;
	}
}

double	ft_normalise_angle(double theta)
{
	theta = remainder(theta, 2.0 * PI);
	if (theta < 0)
		theta = (2.0 * PI) + theta;
	return (theta);
}

void	ft_distance_to_projection_plane(t_player *player)
{
	player->dist_pp = (WIDTH / 2) / tan(FOV / 2);
}

double	ft_dist_btw_pts(double plr_x, double plr_y, double hit_x, double hit_y)
{
	double	distance;

	distance = sqrt(((hit_x - plr_x) * (hit_x - plr_x))
			+ ((hit_y - plr_y) * (hit_y - plr_y)));
	return (distance);
}
