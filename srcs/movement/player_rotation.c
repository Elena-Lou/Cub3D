/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/20 05:57:01 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rotate_left(t_cub_data *data)
{
	data->player.pov -= ((double)PI / 180.0);
	if (data->player.pov < 0.0)
		data->player.pov = (double)PI * 2.0 + data->player.pov;
	return (1);
}

int	ft_rotate_right(t_cub_data *data)
{
	data->player.pov += ((double)PI / 180.0);
	if (data->player.pov > ((double)PI * 2.0))
		data->player.pov = ((double)PI * 2.0) - data->player.pov;
	return (1);
}
