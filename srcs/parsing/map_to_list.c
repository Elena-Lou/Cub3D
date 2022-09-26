/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/26 10:42:09 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

static void	print_lst_map(void *content)
{
	t_map_data	*map_line;

	map_line = content;
	ft_putstr_fd(map_line->line, 1);
}

int	add_line_map(char *line, t_cub_data *data)
{
	t_map_data	*map_data;
	t_list		*new;

	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (free(line), WRONG_MALLOC);
	map_data->line = line;
	map_data->data = data;
	new = ft_lstnew(map_data);
	ft_lstadd_back(&data->lst_map, new);
	return (0);
}

int	map_to_list(t_cub_data *data, char *map_file)
{
	char		*line;
	int			fd;

	fd = open(map_file, O_RDONLY);
	if (ft_check_name(map_file) == WRONG_MAP_NAME)
		return (WRONG_MAP_NAME);
	if (fd < 1)
		return (ft_err_msg(strerror(errno)));
	ft_check_map_content(data);
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), ft_err_msg("Empty map."));
	if (add_line_map(line, data) == WRONG_MALLOC)
		return (close(fd), ft_err_msg("Malloc error."));
	while (line)
	{
		line = get_next_line(fd);
		if (line && add_line_map(line, data) == WRONG_MALLOC)
			return (get_next_line(GNL_FLUSH), ft_err_msg("Malloc error."));
	}
	ft_lstiter(data->lst_map, &print_lst_map);
	ft_putstr_fd("\n", 1);
	close(fd);
	return (0);
}
