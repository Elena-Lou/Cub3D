/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:30:07 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_clear_data_no_tex(t_cub_data *data)
{
	ft_free_strptr(data->grid);
	ft_lstclear(&(data->lst_map), ft_clear_map);
}

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
