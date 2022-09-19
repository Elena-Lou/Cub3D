/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 09:51:36 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_floor(t_cub_data *data, char *line)
{
	(void)data;
	printf("floor line = %s\n", line);
	return (0);
}

int	ft_check_ceilling(t_cub_data *data, char *line)
{
	(void)data;
	printf("ceilling line = %s\n", line);
	return (0);
}

int	ft_check_map_content(t_cub_data *data)
{
	t_map_data	*map;

	while (data->lst_map)
	{
		map = (t_map_data *)data->lst_map;
		if (ft_strncmp(map->line, "F", 1) == 0)
			ft_check_floor(data, map->line);
		else if (ft_strncmp(map->line, "C", 1) == 0)
			ft_check_ceilling(data, map->line);
		data->lst_map = data->lst_map->next;
	}
	return (0);
}
