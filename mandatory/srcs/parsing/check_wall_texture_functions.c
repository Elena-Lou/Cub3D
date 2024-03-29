/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 19:23:29 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include "cub3d.h"

static int	ft_check_path(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NOT_FOUND);
	line = get_next_line(fd);
	if (line == NULL || ft_strcmp(line, "/* XPM */\n") != 0)
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

int	ft_check_texture(t_map_data *map, char **target, char *cmp)
{
	int	ret;

	if (ft_strptr_len(map->flag_and_path) != 2)
		ft_wrong_map_exit(map->data->lst_map, cmp, ": wrong file");
	ret = ft_check_path(map->flag_and_path[1]);
	if (ret == NOT_FOUND)
	{
		ft_wrong_map_exit(map->data->lst_map, cmp, ": no such file");
	}
	if (ret == NOT_XPM)
		ft_wrong_map_exit(map->data->lst_map, cmp, "is not an xpm file");
	if (*target == NULL)
		*target = map->flag_and_path[1];
	else
		ft_wrong_map_exit(map->data->lst_map, cmp,
			"Unauthorized re-definition");
	return (0);
}
