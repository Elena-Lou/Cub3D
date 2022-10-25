/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:20:07 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/25 14:36:37 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hzt_init(t_cub_data *data, t_dda *ray)
{
	ray->inter_y = floor(data->player.y / 64.0) * 64.0;
	if (ray->facing_up == FALSE)
		ray->inter_y += 64.0;
	ray->inter_x = data->player.x + (ray->inter_y - data->player.y)
		/ ray->tan_theta;
	ray->step_y = 64.0;
	if (ray->facing_up == TRUE)
		ray->step_y *= -1.0;
	ray->step_x = 64.0 / ray->tan_theta;
	if (ray->facing_left == TRUE && ray->step_x > 0.0)
		ray->step_x *= -1.0;
	else if (ray->facing_left == FALSE && ray->step_x < 0.0)
		ray->step_x *= -1.0;
	ray->hzt_x = ray->inter_x;
	ray->hzt_y = ray->inter_y;
}

void	ft_hzt_intersections(t_cub_data *data, t_dda *ray)
{
	ray->dir_y = 0;
	if (!ray->facing_up)
		ray->dir_y = -64;
	ft_hzt_init(data, ray);
	while ((int)ray->hzt_x >> 6 > 0 && (int)ray->hzt_x >> 6 < data->map_width
		&& (int)ray->hzt_y >> 6 > 0 && (int)ray->hzt_y >> 6 < data->map_height)
	{
		if (data->grid[(int)(ray->hzt_y + ray->dir_y) >> 6]
			[(int)ray->hzt_x >> 6] == '1')
		{
			ray->hzt_hit = TRUE;
			break ;
		}
		else
		{
			ray->hzt_x += ray->step_x;
			ray->hzt_y += ray->step_y;
		}
	}
}

void	ft_vrt_init(t_cub_data *data, t_dda *ray)
{
	ray->inter_x = floor(data->player.x / 64.0) * 64.0;
	if (ray->facing_left == FALSE)
		ray->inter_x += 64.0;
	ray->inter_y = data->player.y + (ray->inter_x - data->player.x)
		* ray->tan_theta;
	ray->step_x = 64.0;
	if (ray->facing_left == TRUE)
		ray->step_x *= -1.0;
	ray->step_y = 64.0 * ray->tan_theta;
	if (ray->facing_up == TRUE && ray->step_y > 0.0)
		ray->step_y *= -1.0;
	else if (ray->facing_up == FALSE && ray->step_y < 0.0)
		ray->step_y *= -1.0;
	ray->vrt_x = ray->inter_x;
	ray->vrt_y = ray->inter_y;
}

/* superieur strict a peut-être modifié */
void	ft_vrt_intersections(t_cub_data *data, t_dda *ray)
{
	ray->dir_x = 0;
	if (!ray->facing_left)
		ray->dir_x = -64;
	ft_vrt_init(data, ray);
	while ((int)ray->vrt_x >> 6 > 0 && (int)ray->vrt_x >> 6 < data->map_width
		&& (int)ray->vrt_y >> 6 > 0 && (int)ray->vrt_y >> 6 < data->map_height)
	{
		if (data->grid[(int)ray->vrt_y >> 6]
			[(int)(ray->vrt_x + ray->dir_x) >> 6] == '1')
		{
			ray->vrt_hit = TRUE;
			break ;
		}
		else
		{
			ray->vrt_x += ray->step_x;
			ray->vrt_y += ray->step_y;
		}
	}
}

void	ft_cast_ray(t_cub_data *data, t_dda *ray)
{
	ray->tan_theta = tan(ray->theta);
	if (fabs(ray->tan_theta) < 0.0001)
		ray->tan_theta += 0.00001;
	ft_set_dir(ray);
	ft_hzt_intersections(data, ray);
	ft_vrt_intersections(data, ray);
	ray->hzt_dist = ft_dist_btw_pts(data->player.x,
			data->player.y, ray->hzt_x, ray->hzt_y);
	ray->vrt_dist = ft_dist_btw_pts(data->player.x,
			data->player.y, ray->vrt_x, ray->vrt_y);
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
	// ft_draw_line(data, ray->theta, ray->distance, 0xE36414);
	// debug function to print rays in 2D
