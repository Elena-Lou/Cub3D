/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/14 10:18:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_name(char *map_name)
{
	size_t	map_name_size;

	if (map_name == NULL)
		return (write(2, "Wrong map name\n", 15), 1);
	map_name_size = ft_strlen(map_name);
	if (map_name_size < 4)
		return (write(2, "Wrong map name\n", 15), 1);
	if (ft_strncmp(&map_name[map_name_size - 4], ".cub", 4) != 0)
		return (write(2, "Wrong map name\n", 15), 1);
	return (0);
}

int	check_map(t_cub_data *data, char *map_file)
{
	char	*line;
	int		fd;
	int		i;

	(void)data;
	if (ft_check_name(map_file) == 1)
		return (1);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Open error\n", 11), 1);
	i = 0;
	line = get_next_line(fd);
	i++;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		printf("GNL : %s", line);
		i++;
		free(line);
	}
	printf("\ni = %d\n", i);
	close(fd);
	return (0);
}
