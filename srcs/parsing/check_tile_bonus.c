/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:01:56 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:03:32 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_void(char c)
{
	if (c == '1')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	if (c == '0')
		return (0);
	return (1);
}
