/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/16 15:07:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_map(void *list_elem)
{
	t_map_data	*map;

	map = (t_map_data *)list_elem;
	free(map->line);
	map->line = NULL;
	free(map);
	map = NULL;
}
