/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:53:23 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/18 21:59:18 by elouisia         ###   ########.fr       */
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
    wall_size is equal to 64 because it the size of the tiles
    ray->distance is the actual distance from the player to wall
    
    strip_height = wall_size / ray->distance * distance_to_pp
*/

static void	ft_render_wall(t_cub_data *data, int top, int bottom, t_dda *ray)
{
	int	y;
	int x;

	x = ray->id;
	y = top;
	while (y < bottom)
	{
		ft_put_pix_img(&data->img, x, y, 0x12354d);
		y++;
	}
}

void	ft_wall_scaling(t_cub_data *data, t_dda *ray)
{
    // printf("WALL SCALING\n");
	ray->strip_height = (64 / ray->distance) * data->player.dist_pp;
	// printf("Yo\n");
}

void	ft_wall_projection(t_cub_data *data, t_dda *ray)
{
	int	wall_top;
	int	wall_bottom;
    
    // printf("WALL PROJECTION\n");
	ft_wall_scaling(data, ray);
	wall_top = (HEIGHT / 2) - (ray->strip_height / 2);
	if (wall_top < 0)
		wall_top = 0;
	// printf("top : %d\n", wall_top);
	wall_bottom = (HEIGHT / 2) + (ray->strip_height / 2);
	if (wall_bottom > HEIGHT)
		wall_bottom = HEIGHT;
	// printf("bottom : %d\n", wall_bottom);
    // printf("top = %d - bottom = %d\n", wall_top, wall_bottom);
	ft_render_wall(data, wall_top, wall_bottom, ray);
	// printf("end of function\n");
}
