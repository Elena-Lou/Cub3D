/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:56:29 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/21 09:56:34 by aweaver          ###   ########.fr       */
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
