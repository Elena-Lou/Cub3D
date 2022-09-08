/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:04:09 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/08 18:05:19 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_cub_data *data, char *map_file)
{
	char	*str;
	int		fd;
	int		i;
	(void)data;
	
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		printf("GNL : %s\n", str);
		if (str)
			break ;
		else if (str[0] != '\n')
			i++;
	}
	printf("i = %d\n", i);
	return (0);
}
