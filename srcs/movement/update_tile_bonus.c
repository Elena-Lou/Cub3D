/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tile_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:30:04 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update_player_tile(t_cub_data *data, int tile_x, int tile_y)
{
	data->player.x = (double)tile_x * 64.0 + 32.0;
	data->player.y = (double)tile_y * 64.0 + 32.0;
	data->player.tile_x = tile_x;
	data->player.tile_y = tile_y;
}
