/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:40:38 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/07 13:26:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
A_ Cast a ray
    1_ Find Horizontal intersections
    
- find coordinates of the first intersection

- d_y, the height of a grid cell == 1.

- delta_x : the distance between each horizontal intersection
-> delta_x = d_y / tan(FOV)

- if there is a wall on the cell, stop to calculate the distance

- else, move on to the next horizontal intersection :
    Xnew = Xold + delta_x
    Ynew = Yold + d_y

    2_ Find vertical intersections
    
- find coordinates of the first intersection

- d_x, the width of a grid cell == 1

- delta_y : the distance between each vertical intersection
-> delta_y = d_x * tan(FOV)

- if there is a wall, stop to calculate the distance

- else, move on to the next vertical intersection :
    Xnew = Xold + d_x
    Ynew = Yold + delta_y
*/

// void	ft_launch_no_ea(t_cub_data *data, t_dda *ray, double tan)
// {
// 	while (1)
// 	{
// 		while (ray->inter_y)
// 	}
// }

//void	ft_ray_launcher(t_cub_data *data, t_dda *ray, double tan)
//{
	//if (ray->dir_x == 1 && ray->dir_y == -1)
		//ft_launch_no_ea(data, ray, tan);
	//else if (ray->dir_x == -1 && ray->dir_y == -1)
		//ft_launch_no_we(data, ray, tan);
	//else if (ray->dir_x == -1 && ray->dir_y == 1)
		//ft_launch_so_we(data, ray, tan);
	//else
		//ft_launch_no_ea(data, ray, tan);
//}
//
//void	ft_set_dir(t_dda *ray, double tan)
//{
	//if (ray->theta > WEST || ray->theta < EAST)
		//ray->dir_y = -1;
	//else
		//ray->dir_y = 1;
	//if (ray->theta > NORTH || ray->theta < SOUTH)
		//ray->dir_x = 1;
	//else
		//ray->dir_x = -1;
//}
//
//void	ft_set_ray_data(t_cub_data *data)
//{
	//t_dda	ray;
	//double	theta;
	//double	tan_theta;
//
	//ray.pos_x = data->player.x;
	//ray.pos_y = data->player.y;
	//data->player.tile_x = data->player.x >> 6;
	//data->player.tile_y = data->player.y >> 6;
	//ray.theta = data->player.pov - (FOV / 2);
	//tan_theta = tan(theta);
	//ray.inter_x = ray.pos_x + (ray.d_y / tan_theta);
	//ray.inter_y = ray.pos_y + (ray.d_x * tan_theta);
	//ft_set_dir(&ray, tan_theta);
	//ray.step_x = ray.dir_x * tan_theta;
	//ray.step_y = ray.dir_y / tan_theta;
	//ft_ray_launcher(data, &ray, tan_theta);
//}
