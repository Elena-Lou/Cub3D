/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:56:29 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/20 11:57:46 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update_player_tile(t_cub_data *data, int x, int y)
{
	data->player.tile_x = x;
	data->player.tile_y = y;
}
