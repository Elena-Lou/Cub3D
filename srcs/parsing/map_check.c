/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/13 17:55:07 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_lst_map(void *content)
{
	t_map_data	*map_line;

	map_line = content;
	printf("line : %s\n", map_line->line);
}

int	add_line_map(char *line, t_cub_data *data)
{
	t_map_data	*map_data;
	t_list		*new;

	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
	{
		free(line);
		return (1);
	}
	map_data->line = ft_strdup(line);
	new = ft_lstnew(map_data);
	ft_lstadd_back(&data->lst_map, new);
	return (0);
}

void	map_to_list(t_cub_data *data, char *map_file)
{
	char		*line;

	data->fd = open(map_file, O_RDONLY);
	if (data->fd < 1)
		exit(write(2, "Open Error\n", 11));
	if (ft_check_name(map_file) == 1)
		return (1);
	line = get_next_line(data->fd);
	if (!line)
		return ;
	if (add_line_map(line, data))
		return ;
	while (line)
	{
		free(line);
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if (add_line_map(line, data))
			return ;
	}
	close(data->fd);
	ft_lstiter(data->lst_map, &print_lst_map);
}
