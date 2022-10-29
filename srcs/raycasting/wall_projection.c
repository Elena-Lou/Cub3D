/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:23 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/29 19:31:35 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*

         ___ Projection Plane _________________
        |
        |
        |   ************ Top of the wall
        |
        |   ------------ Middle of PP
        |
        |   ************ Bottom of the wall
        |
        |______________________________________

    strip_height is the scaled height of the wall.
    wall_size is equal to 64 because it is the size of the tiles
    ray->distance is the actual distance from the player to wall
    
    strip_height = wall_size / ray->distance * distance_to_pp
*/

static double	ft_glasses_for_fishes(t_cub_data *data, t_dda *ray)
{
	double	correct_dist;

	correct_dist = ray->distance * cos(ray->theta - data->player.pov);
	return (correct_dist);
}

void	ft_wall_scaling(t_cub_data *data, t_dda *ray)
{
	double	distance;

	distance = ft_glasses_for_fishes(data, ray);
	ray->strip_height = (64.0 / distance) * data->player.dist_pp;
}

void	ft_wall_projection(t_cub_data *data, t_dda *ray)
{
	int	wall_top;
	int	wall_bottom;

	ft_wall_scaling(data, ray);
	wall_top = (HEIGHT / 2) - (ray->strip_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = (HEIGHT / 2) + (ray->strip_height / 2);
	if (wall_bottom > HEIGHT)
		wall_bottom = HEIGHT;
	ft_render_wall(data, wall_top, wall_bottom, ray);
}
