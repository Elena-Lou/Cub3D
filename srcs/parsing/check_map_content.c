/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 13:42:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_header(void *arg)
{
	t_map_data			*map;
	const char			*comp[] = {"NO", "SO", "EA", "WE", "F", "C"};
	const t_check		ft_check[] = {&ft_check_no, &ft_check_so, &ft_check_ea,
		&ft_check_we, &ft_check_floor, &ft_check_ceilling};
	int					i;

	i = 0;
	map = (t_map_data *)arg;
	if (map->flag_and_path == NULL || *(map->flag_and_path) == NULL)
		return ;
	while (i < 6)
	{
		if (ft_strcmp(*map->flag_and_path, comp[i]) == 0)
		{
			if ((*ft_check[i])(map) == 1)
				return ;
			break ;
		}
		i++;
	}
}

void	ft_tokenise_map(void *arg)
{
	t_map_data	*map_data;

	if (arg == NULL)
		return ;
	map_data = (t_map_data *)arg;
	map_data->flag_and_path = ft_split_f(map_data->line, &ft_iswhitespace);
	if (*map_data->flag_and_path && (**map_data->flag_and_path == '0'
			|| **map_data->flag_and_path == '1'))
		map_data->flag_and_path = ft_free_double_array(map_data->flag_and_path);
}

int	ft_check_map_content(t_cub_data *data)
{
	ft_lstiter(data->lst_map, &ft_tokenise_map);
	ft_lstiter(data->lst_map, &ft_check_map_header);
	return (0);
}
