/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 12:06:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "cub3d.h"
#include "get_next_line.h"

int	ft_check_path(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (ft_strcmp(line, "/* XPM */") != 0)
	{
		free(line);
		line = NULL;
		get_next_line(GNL_FLUSH);
		return (1);
	}
	free(line);
	line = NULL;
	get_next_line(GNL_FLUSH);
	return (0);
}

int	ft_check_no(t_map_data *map)
{
	if (map->flag_and_path == NULL || *map->flag_and_path == NULL)
		map->data->error = 1;
	if (ft_strptr_len(map->flag_and_path) != 2)
		map->data->error = 1;
	if (ft_check_path(map->flag_and_path[1]) == 1)
		map->data->error = 1;
	if (DEBUG)
	{
		printf("no flag = %s\n", *map->flag_and_path);
		printf("no path = %s\n", (*(map->flag_and_path + 1)));
	}
	if (map->data->error == 0)
		map->data->no = map->flag_and_path[1];
	else
		ft_wrong_map(map->data->lst_map);
	return (0);
}

int	ft_check_so(t_map_data *map)
{
	if (map->flag_and_path == NULL || *map->flag_and_path == NULL)
		map->data->error = 1;
	if (ft_strptr_len(map->flag_and_path) != 2)
		map->data->error = 1;
	if (ft_check_path(map->flag_and_path[1]) == 1)
		map->data->error = 1;
	if (DEBUG)
	{
		printf("no flag = %s\n", *map->flag_and_path);
		printf("no path = %s\n", (*(map->flag_and_path + 1)));
	}
	if (map->data->error == 0)
		map->data->so = map->flag_and_path[1];
	else
		return (1);
	return (0);
}

int	ft_check_ea(t_map_data *map)
{
	if (map->flag_and_path == NULL || *map->flag_and_path == NULL)
		map->data->error = 1;
	if (ft_strptr_len(map->flag_and_path) != 2)
		map->data->error = 1;
	if (ft_check_path(map->flag_and_path[1]) == 1)
		map->data->error = 1;
	if (DEBUG)
	{
		printf("no flag = %s\n", *map->flag_and_path);
		printf("no path = %s\n", (*(map->flag_and_path + 1)));
	}
	if (map->data->error == 0)
		map->data->ea = map->flag_and_path[1];
	else
		return (1);
	return (0);
}

int	ft_check_we(t_map_data *map)
{
	if (map->flag_and_path == NULL || *map->flag_and_path == NULL)
		map->data->error = 1;
	if (ft_strptr_len(map->flag_and_path) != 2)
		map->data->error = 1;
	if (ft_check_path(map->flag_and_path[1]) == 1)
		map->data->error = 1;
	if (DEBUG)
	{
		printf("no flag = %s\n", *map->flag_and_path);
		printf("no path = %s\n", (*(map->flag_and_path + 1)));
	}
	if (map->data->error == 0)
		map->data->we = map->flag_and_path[1];
	else
		return (1);
	return (0);
}
