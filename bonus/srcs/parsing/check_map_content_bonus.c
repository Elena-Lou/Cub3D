/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:39 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/30 10:41:41 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_map_header(void *arg)
{
	t_map_data			*map;
	const char			*comp[] = {"NO", "SO", "EA", "WE", "F", "C"};
	int					i;

	i = 0;
	map = (t_map_data *)arg;
	if (map->flag_and_path == NULL || *(map->flag_and_path) == NULL)
		return ;
	while (i < 6)
	{
		if (ft_strcmp(*map->flag_and_path, comp[i]) == 0)
		{
			if (i < 4)
				ft_check_texture(map, &map->data->tex[i].path, (char *)comp[i]);
			else if (i == 4)
				ft_check_floor_ceiling(map,
					&map->data->floor, (char *)comp[i]);
			else
				ft_check_floor_ceiling(map,
					&map->data->ceilling, (char *)comp[i]);
			return ;
		}
		i++;
	}
}

static void	ft_tokenise_map(void *arg)
{
	t_map_data	*map_data;

	if (arg == NULL)
		return ;
	map_data = (t_map_data *)arg;
	map_data->flag_and_path = ft_split_f(map_data->line, &ft_iswhitespace);
	if (*map_data->flag_and_path && (**map_data->flag_and_path == '0'
			|| **map_data->flag_and_path == '1'))
		map_data->flag_and_path = ft_free_strptr(map_data->flag_and_path);
}

static void	ft_check_texture_all_set(t_cub_data *data)
{
	int			i;
	const char	*texture[] = {"North: ", "South: ", "East: ", "West: "};

	i = 0;
	while (i < 4)
	{
		if (data->tex[i].path == NULL)
			ft_wrong_map_exit(data->lst_map, (char *)texture[i], "not set.");
		i++;
	}
	if (data->floor == -1)
		ft_wrong_map_exit(data->lst_map, "Floor: ", "not set.");
	else if (data->ceilling == -1)
		ft_wrong_map_exit(data->lst_map, "Ceilling: ", "not set.");
}

void	ft_check_map_content(t_cub_data *data)
{
	ft_lstiter(data->lst_map, &ft_tokenise_map);
	ft_lstiter(data->lst_map, &ft_check_map_header);
	ft_check_texture_all_set(data);
	ft_create_map_grid(data);
	ft_check_map_grid(data, data->grid);
	data->map_width = ft_strlen_int(*data->grid);
	data->map_height = ft_strptr_len(data->grid);
}
