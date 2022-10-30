/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/30 18:16:29 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// aka ft_check if grid is before map
static int	ft_c_grid(void *arg)
{
	t_map_data			*map;

	map = (t_map_data *)arg;
	if (ft_is_valid_map_char(*(map->flag_and_path)[0])
			&& ft_check_texture_all_set(arg) != 0)
		exit (1);
	return (1);
}

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
		printf("test A\n");
		printf("flag and path = %s, comp[i] = %s\n", *map->flag_and_path, comp[i]);
		if (ft_strcmp(*map->flag_and_path, comp[i]) == 0 && ft_c_grid(arg))
		{
			printf("entered here i = %d\n", i);
			if (i < 4)
			{
				ft_check_texture(map, &map->data->tex[i].path, (char *)comp[i]);
				printf("DEBUG: >%p<\n", &map->data->tex[i].path);
			}
			else if (i == 4)
				ft_check_floor_ceiling(map,
					&map->data->floor, (char *)comp[i]);
			else
				ft_check_floor_ceiling(map,
					&map->data->ceiling, (char *)comp[i]);
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
	if (*map_data->flag_and_path
		&& ft_is_valid_map_char(**map_data->flag_and_path) && ft_check_texture_all_set(map_data->data) == 0)
		map_data->flag_and_path = ft_free_strptr(map_data->flag_and_path);
}

int	ft_check_texture_all_set(t_cub_data *data)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (data->tex[i].path == NULL)
			return (i + 1);
		i++;
	}
	if (data->floor == -1)
		return (NO_FLOOR);
	else if (data->ceiling == -1)
		return (NO_CEILING);
	return (0);
}

void	ft_check_map_content(t_cub_data *data)
{
	const char	*texture[] = {"North: ", "South: ", "East: ", "West: ",
		"floor", "Ceiling"};
	int			ret;

	ret = 0;
	ft_lstiter(data->lst_map, &ft_tokenise_map);
	ft_lstiter(data->lst_map, &ft_check_map_header);
	for (int i = 0; i < 4; i++)
		printf("DEBUG: >%p<\n", data->tex[i].path);
	ret = ft_check_texture_all_set(data);
	printf("ret = %d\n", ret);
	if (ret)
		ft_wrong_map_exit(data->lst_map, (char *)texture[ret - 1],
			"is invalid.");
	ft_create_map_grid(data);
	ft_check_map_grid(data, data->grid);
	data->map_width = ft_strlen_int(*data->grid);
	data->map_height = ft_strptr_len(data->grid);
}
