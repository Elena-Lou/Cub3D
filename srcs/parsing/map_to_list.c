/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/20 13:44:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (free(line), 1);
	map_data->line = line;
	map_data->data = data;
	new = ft_lstnew(map_data);
	ft_lstadd_back(&data->lst_map, new);
	return (0);
}

int	map_to_list(t_cub_data *data, char *map_file)
{
	char		*line;

	data->fd = open(map_file, O_RDONLY);
	if (ft_check_name(map_file) == 1)
		return (1);
	if (data->fd < 1)
		return (write(2, "Open Error\n", 11), 1);
	if (ft_check_map_content(data) == 1)
		return (1);
	line = get_next_line(data->fd);
	if (line == NULL || add_line_map(line, data))
		return (1);
	while (line)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if (add_line_map(line, data) == 1)
			return (get_next_line(GNL_FLUSH), 1);
	}
	close(data->fd);
	ft_lstiter(data->lst_map, &print_lst_map);
	ft_putstr_fd("\n", 1);
	return (0);
}
