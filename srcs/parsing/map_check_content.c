/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 11:37:26 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_content(t_cub_data *data)
{
	t_map_data			*map;
	static const char	*comp[] = {"NO", "SO", "EA", "WE", "F", "C", "\0"};
	static t_check		ft_check[] = {&ft_check_no, &ft_check_so, &ft_check_ea,
		&ft_check_we, &ft_check_floor, &ft_check_ceilling};
	int					i;

	i = 0;
	printf("\nEntered ft_check_map_content function\n");
	while (data->lst_map)
	{
		map = (t_map_data *)data->lst_map->content;
		while (i < 6)
		{
			if (ft_strcmp(map->line, comp[i]) == 0)
			{
				if ((*ft_check[i])(data, map->line) == 1)
					return (1);
			}
			i++;
		}
		data->lst_map = data->lst_map->next;
	}
	return (0);
}
