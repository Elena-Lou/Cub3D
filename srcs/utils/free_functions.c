/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:51:37 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/26 08:37:35 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_clear_data(t_cub_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(data->tex[i].path);
		data->tex[i].path = NULL;
		i++;
	}
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

void	ft_clear_textures(t_cub_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->tex[i].img);
		i++;
	}
}
