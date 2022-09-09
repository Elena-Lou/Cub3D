/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/09 14:52:55 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_cub_data *data, char *map_file)
{
	char	*line;
	int		fd;
	int		i;
	(void)data;
	
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Open error\n", 11);
		return (1);
	}
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
