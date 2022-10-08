/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:41:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/07 18:31:41 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rotate_left(t_cub_data *data)
{
	data->player.pov -= PI / 8.0;
	if (data->player.pov < 0.0)
		data->player.pov = 5.8904852;
	return (0);
}

int	ft_rotate_right(t_cub_data *data)
{
	data->player.pov += PI / 8.0;
	if (data->player.pov > (PI * 2.0))
		data->player.pov = 0.0;
	return (0);
}
