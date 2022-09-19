/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:03:10 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 12:11:19 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_name(char *map_name)
{
	size_t	map_name_size;

	if (map_name == NULL)
		return (write(2, "Wrong map name\n", 15), 1);
	map_name_size = ft_strlen(map_name);
	if (map_name_size < 4)
		return (write(2, "Wrong map name\n", 15), 1);
	if (ft_strncmp(&map_name[map_name_size - 4], ".cub", 4) != 0)
		return (write(2, "Wrong map name\n", 15), 1);
	return (0);
}
