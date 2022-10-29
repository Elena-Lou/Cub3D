/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:01:58 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:03:32 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

static void	ft_print_lst_map(void *content)
{
	t_map_data	*map_line;

	map_line = content;
	ft_putstr_fd(map_line->line, 1);
}

int	ft_add_line_map(char *line, t_cub_data *data)
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

int	ft_map_to_list(t_cub_data *data, char *map_file)
{
	char		*line;
	int			fd;

	if (ft_check_name(map_file) == WRONG_MAP_NAME)
		return (WRONG_MAP_NAME);
	fd = open(map_file, O_RDONLY);
	if (fd < 1)
		return (ft_err_msg(strerror(errno)));
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), ft_err_msg("Map is empty or is not a valid file."));
	if (ft_add_line_map(line, data) == WRONG_MALLOC)
		return (close(fd), ft_err_msg("Malloc error."));
	while (line)
	{
		line = get_next_line(fd);
		if (line && ft_add_line_map(line, data) == WRONG_MALLOC)
			return (get_next_line(GNL_FLUSH), ft_err_msg("Malloc error."));
	}
	if (SHOW_MAP)
		ft_lstiter(data->lst_map, &ft_print_lst_map);
	ft_putstr_fd("\n", 1);
	close(fd);
	return (0);
}
