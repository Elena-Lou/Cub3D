/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 16:26:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_header(t_cub_data *data)
{
	t_map_data			*map;
	static const char	*comp[] = {"NO", "SO", "EA", "WE", "F", "C"};
	static t_check		ft_check[] = {&ft_check_no, &ft_check_so, &ft_check_ea,
		&ft_check_we, &ft_check_floor, &ft_check_ceilling};
	int					i;

	i = 0;
	while (data->lst_map)
	{
		map = (t_map_data *)data->lst_map->content;
		while (i < 6)
		{
			if (ft_strcmp(*map->flag_and_path, comp[i]) == 0)
			{
				if ((*ft_check[i])(data, map->flag_and_path) == 1)
					return (1);
			}
			i++;
		}
		data->lst_map = data->lst_map->next;
	}
	return (0);
}

void	ft_tokenise_map(void *arg)
{
	t_map_data	*map_data;

	if (arg == NULL)
		return ;
	map_data = (t_map_data *)arg;
	map_data->flag_and_path = ft_split_f(map_data->line, &ft_iswhitespace);
	printf("no flag = %s\n", *map_data->flag_and_path);
	printf("no path = %s\n", (*(map_data->flag_and_path + 1)));
}

int	ft_check_map_content(t_cub_data *data)
{
	ft_lstiter(data->lst_map, &ft_tokenise_map);
	if (ft_check_map_header(data) == 1)
		return (1);
	return (0);
}
