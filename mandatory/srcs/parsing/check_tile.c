/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:19:48 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/28 19:20:06 by aweaver          ###   ########.fr       */
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
