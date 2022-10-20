/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:19:23 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/18 21:59:27 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
