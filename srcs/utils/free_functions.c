/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 14:20:37 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_wrong_map(t_list *list, char *texture, char *error_msg)
{
	t_map_data	*map;
	t_cub_data	*data;

	map = (t_map_data *)list->content;
	data = map->data;
	ft_clear_data(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(texture, 2);
	ft_putstr_fd(error_msg, 2);
	exit(1);
}

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
	ft_lstclear(&(data->lst_map), ft_clear_map);
}

void	ft_clear_map(void *list_elem)
{
	t_map_data	*map;

	map = (t_map_data *)list_elem;
	free(map->line);
	map->line = NULL;
	map->flag_and_path = ft_free_double_array(map->flag_and_path);
	free(map);
	map = NULL;
}
