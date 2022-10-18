/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:40:38 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/20 15:02:25 by elouisia         ###   ########.fr       */
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

// double	ft_normalize_angle(double theta)
// {
// 	if (theta < 0)
// 		theta += (2 * PI);
// 	return (theta);
// }

void	ft_set_ray_data(t_cub_data *data)
{
	t_dda	ray[WIDTH];
	int		i;

	i = 0;
	// printf("\n ----SET RAY DATA----\n");
	ft_distance_to_projection_plane(&data->player);
	// printf("set ray --- after distpp\n");
	ray[0].theta = data->player.pov - (FOV / 2);
	// printf("ray[0] theta : %f\n", ray[i].theta);
	while (i < WIDTH)
	{
		// printf("while set ray\n");
		// printf("ray[%d] theta : %f\n", i,  ray[i].theta);
		ray[i].id = i;
		ft_cast_ray(data, &ray[i]);
		// printf("after ft_cast_ray\n");
		ft_wall_projection(data, &ray[i]);
		// printf("after wall projection\n");
		if (i + 1 < WIDTH)
			ray[i + 1].theta = ray[i].theta	+ (FOV / WIDTH);
		i++;

		// ray[i].theta = (ray[i].theta + (FOV / WIDTH));
		// printf("ray[%d] theta : %f\n", i,  ray[i].theta);

	}
}
