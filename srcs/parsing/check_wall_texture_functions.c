/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 16:02:53 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
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
	if (line == NULL || ft_strcmp(line, "/* XPM */") != 0)
	{
		free(line);
		line = NULL;
		get_next_line(GNL_FLUSH);
		return (2);
	}
	free(line);
	line = NULL;
	get_next_line(GNL_FLUSH);
	return (0);
}

int	ft_check_no(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map(map->data->lst_map, "Texture NO: ", "wrong file\n");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == 1)
		ft_wrong_map(map->data->lst_map, "Texture NO: ", strerror(errno));
	if (ret == 2)
		ft_wrong_map(map->data->lst_map, "Texture NO:", "is not an xpm file\n");
	if (map->data->no == NULL)
		map->data->no = map->flag_and_path[1];
	else
		ft_wrong_map(map->data->lst_map, "Texture NO:",
			"Unauthorized re-definition\n");
	return (0);
}

int	ft_check_so(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map(map->data->lst_map, "Texture SO: ", "wrong file\n");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == 1)
		ft_wrong_map(map->data->lst_map, "Texture SO: ", strerror(errno));
	if (ret == 2)
		ft_wrong_map(map->data->lst_map, "Texture SO:", "is not an xpm file\n");
	if (map->data->so == NULL)
		map->data->so = map->flag_and_path[1];
	else
		ft_wrong_map(map->data->lst_map, "Texture SO:",
			"Unauthorized re-definition\n");
	return (0);
}

int	ft_check_ea(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map(map->data->lst_map, "Texture EA: ", "wrong file name\n");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == 1)
		ft_wrong_map(map->data->lst_map, "Texture EA: ", strerror(errno));
	if (ret == 2)
		ft_wrong_map(map->data->lst_map, "Texture EA:", "is not an xpm file\n");
	if (map->data->ea == NULL)
		map->data->ea = map->flag_and_path[1];
	else
		ft_wrong_map(map->data->lst_map, "Texture EA:",
			"Unauthorized re-definition\n");
	return (0);
}

int	ft_check_we(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map(map->data->lst_map, "Texture WE: ", "wrong file\n");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == 1)
		ft_wrong_map(map->data->lst_map, "Texture WE: ", strerror(errno));
	if (ret == 2)
		ft_wrong_map(map->data->lst_map, "Texture WE:", "is not an xpm file\n");
	if (map->data->we == NULL)
		map->data->we = map->flag_and_path[1];
	else
		ft_wrong_map(map->data->lst_map, "Texture WE:",
			"Unauthorized re-definition\n");
	return (0);
}
