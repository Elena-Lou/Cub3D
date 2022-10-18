/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:20:07 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/18 22:48:42 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hzt_init(t_cub_data *data, t_dda *ray)
{
	// printf("HZT INIT\n");
	ray->inter_y = floor(data->player.y / 64) * 64;
	if (ray->facing_up == FALSE)
		ray->inter_y += 64;
	else
		ray->inter_y -= 1;
	ray->inter_x = data->player.x + (ray->inter_y - data->player.y)
		/ ray->tan_theta;
	ray->step_y = 64;
	if (ray->facing_up == TRUE)
		ray->step_y *= -1;
	ray->step_x = 64 / ray->tan_theta;
	if (ray->facing_left == TRUE && ray->step_x > 0)
		ray->step_x *= -1;
	else if (ray->facing_left == FALSE && ray->step_x < 0)
		ray->step_x *= -1;
	ray->hzt_x = ray->inter_x;
	ray->hzt_y = ray->inter_y;
}

void	ft_hzt_intersections(t_cub_data *data, t_dda *ray)
{
	// printf("HZT INTERSECTION\n");
	ft_hzt_init(data, ray);
	// printf("hzt intersection after init\n");
	while (ray->hzt_x >= 0 && ray->hzt_x >> 6 <= data->map_width && ray->hzt_y >= 0 && ray->hzt_y >> 6 <= data->map_height)
	{
		// printf("hzt intersection while\n");
		// printf("hzt_x : %d - hzt_y : %d\n", ray->hzt_x, ray->hzt_y);
		if (data->grid[ray->hzt_y >> 6][ray->hzt_x >> 6] == '1')
		{
			// printf("hzt intersection if \n");
			ray->hzt_hit = TRUE;
			break ;
		}
		else
		{
			// printf("hzt intersection else \n");
			ray->hzt_x += ray->step_x;
			ray->hzt_y += ray->step_y;
		}
		// printf("HEY !\n");
	}
	// printf("end of hzt intersection \n");
}

void	ft_vrt_init(t_cub_data *data, t_dda *ray)
{
	// printf("VRT INIT\n");
	ray->inter_x = floor(data->player.x / 64) * 64;
	if (ray->facing_left == FALSE)
		ray->inter_x += 64;
	else
		ray->inter_x -= 1;
	ray->inter_y = data->player.y + (ray->inter_x - data->player.x)
		* ray->tan_theta;
	ray->step_x = 64;
	if (ray->facing_left == TRUE)
		ray->step_x *= -1;
	ray->step_y = 64 * ray->tan_theta;
	if (ray->facing_up == TRUE && ray->step_y > 0)
		ray->step_y *= -1;
	else if (ray->facing_up == FALSE && ray->step_y < 0)
		ray->step_y *= -1;
	ray->vrt_x = ray->inter_x;
	ray->vrt_y = ray->inter_y;
}

void	ft_vrt_intersections(t_cub_data *data, t_dda *ray)
{
	// printf("VRT INTERSECTION\n");
	ft_vrt_init(data, ray);
	// printf("vrt intersection after init\n");
	while (ray->vrt_x >= 0 && ray->vrt_x >> 6 <= data->map_width && ray->vrt_y >= 0 && ray->vrt_y >> 6 <= data->map_height)
	{
		// printf("vrt while\n");
		// printf("vrt_x : %d - vrt_y : %d\n", ray->vrt_x, ray->vrt_y);
		// printf("hit : [%c]\n", data->grid[ray->vrt_y >> 6][ray->vrt_x >> 6]);
		if (data->grid[ray->vrt_y >> 6][ray->vrt_x >> 6] == '1')
		{
			// printf("vrt if\n");
			ray->vrt_hit = TRUE;
			break ;
		}
		else
		{
			// printf("vrt else\n");
			ray->vrt_x += ray->step_x;
			ray->vrt_y += ray->step_y;
		}
		// printf("BOUH !\n");
	}
	// printf("end of vrt intersection ft\n");
}

void	ft_cast_ray(t_cub_data *data, t_dda *ray)
{
	// printf("FT CAST RAY\n");
	// ray->theta = ft_normalize_angle(ray->theta);
	ray->tan_theta = tan(ray->theta);
	ft_set_dir(ray);
	ft_hzt_intersections(data, ray);
	ft_vrt_intersections(data, ray);
	// printf("cast ray, after intersections\n");
	ray->hzt_dist = ft_dist_btw_pts((double)data->player.x,
			(double)data->player.y, (double)ray->hzt_x, (double)ray->hzt_y);
	ray->vrt_dist = ft_dist_btw_pts((double)data->player.x,
			(double)data->player.y, (double)ray->vrt_x, (double)ray->vrt_y);
	if (ray->vrt_dist < ray->hzt_dist)
		ray->distance = ray->vrt_dist;
	else
		ray->distance = ray->hzt_dist;
}
