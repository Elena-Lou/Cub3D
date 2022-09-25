/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/23 08:28:19 by aweaver          ###   ########.fr       */
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
		return (NOT_FOUND);
	line = get_next_line(fd);
	if (line == NULL || ft_strcmp(line, "/* XPM */") != 0)
	{
		free(line);
		line = NULL;
		get_next_line(GNL_FLUSH);
		close(fd);
		return (NOT_XPM);
	}
	free(line);
	line = NULL;
	get_next_line(GNL_FLUSH);
	close(fd);
	return (0);
}

int	ft_check_no(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map_exit(map->data->lst_map, "Texture NO: ", "wrong file");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == NOT_FOUND)
		ft_wrong_map_exit(map->data->lst_map, "Texture NO: ", strerror(errno));
	if (ret == NOT_XPM)
		ft_wrong_map_exit(map->data->lst_map, "Texture NO:",
			"is not an xpm file");
	if (map->data->no == NULL)
		map->data->no = map->flag_and_path[1];
	else
		ft_wrong_map_exit(map->data->lst_map, "Texture NO:",
			"Unauthorized re-definition");
	return (0);
}

int	ft_check_so(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map_exit(map->data->lst_map, "Texture SO: ", "wrong file");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == NOT_FOUND)
		ft_wrong_map_exit(map->data->lst_map, "Texture SO: ", strerror(errno));
	if (ret == NOT_XPM)
		ft_wrong_map_exit(map->data->lst_map, "Texture SO:",
			"is not an xpm file");
	if (map->data->so == NULL)
		map->data->so = map->flag_and_path[1];
	else
		ft_wrong_map_exit(map->data->lst_map, "Texture SO:",
			"Unauthorized re-definition");
	return (0);
}

int	ft_check_ea(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map_exit(map->data->lst_map, "Texture EA: ",
			"wrong file name");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == NOT_FOUND)
		ft_wrong_map_exit(map->data->lst_map, "Texture EA: ", strerror(errno));
	if (ret == NOT_XPM)
		ft_wrong_map_exit(map->data->lst_map, "Texture EA:",
			"is not an xpm file");
	if (map->data->ea == NULL)
		map->data->ea = map->flag_and_path[1];
	else
		ft_wrong_map_exit(map->data->lst_map, "Texture EA:",
			"Unauthorized re-definition");
	return (0);
}

int	ft_check_we(t_map_data *map)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
	{
		ft_wrong_map_exit(map->data->lst_map, "Texture WE: ", "wrong file");
		map->data->error = 1;
	}
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == NOT_FOUND)
		ft_wrong_map_exit(map->data->lst_map, "Texture WE: ", strerror(errno));
	if (ret == NOT_XPM)
		ft_wrong_map_exit(map->data->lst_map, "Texture WE:",
			"is not an xpm file");
	if (map->data->we == NULL)
		map->data->we = map->flag_and_path[1];
	else
		ft_wrong_map_exit(map->data->lst_map, "Texture WE:",
			"Unauthorized re-definition");
	return (0);
}
