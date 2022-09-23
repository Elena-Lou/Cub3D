/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor_texture_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:41 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/23 08:26:12 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_value(char *str, int *colour)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			if (ft_iswhitespace(str[i]) == 0)
				if (str[i] != '+')
					if (str[i] != '-')
						return (1);
		i++;
	}
	*colour = ft_atoi(str);
	return (0);
}

int	ft_check_floor(t_map_data *map)
{
	char	*tmp;
	int		rgb[3];
	int		i;

	tmp = ft_strptr_to_str(map->flag_and_path + 1);
	map->flag_and_path = ft_free_strptr(map->flag_and_path);
	map->flag_and_path = ft_split(tmp, ',');
	free(tmp);
	if (ft_strptr_len(map->flag_and_path) != 3)
	{
		ft_free_strptr(map->flag_and_path);
		ft_wrong_map_exit(map->data->lst_map, "F: ", "not a valid colour");
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_check_value(tmp, &rgb[i]) == 1)
			return (free(tmp), ft_free_strptr(map->flag_and_path),
				ft_wrong_map_exit(map->data->lst_map, "Texture F: ",
					"not a valid colour"), 1);
	}
	return (0);
}

int	ft_check_ceilling(t_map_data *map)
{
	printf("ceilling flag = %s\n", *map->flag_and_path);
	printf("ceilling path = %s\n", (*(map->flag_and_path + 1)));
	return (0);
}
