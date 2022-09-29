/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/29 11:30:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_clear_data(t_cub_data *data)
{
	free(data->no);
	data->no = NULL;
	free(data->so);
	data->so = NULL;
	free(data->ea);
	data->ea = NULL;
	free(data->we);
	data->we = NULL;
	ft_free_strptr(data->grid);
	ft_lstclear(&(data->lst_map), ft_clear_map);
}

void	ft_clear_map(void *list_elem)
{
	t_map_data	*map;

	map = (t_map_data *)list_elem;
	free(map->line);
	map->line = NULL;
	map->flag_and_path = ft_free_strptr(map->flag_and_path);
	free(map);
	map = NULL;
}
