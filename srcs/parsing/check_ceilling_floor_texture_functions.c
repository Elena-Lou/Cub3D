/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor_texture_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:41 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/26 08:49:13 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_argb(int a, int red, int green, int blue)
{
	double	argb;

	if (red >= 255)
		red = 255;
	if (green >= 255)
		green = 255;
	if (blue >= 255)
		blue = 255;
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	argb = a << 24 | red << 16 | green << 8 | blue;
	return (argb);
}

int	ft_check_redefinition(t_map_data *map, char *col_name, int *colour,
	int new_colour)
{
	if (*colour == -1)
	{
		*colour = new_colour;
		return (0);
	}
	else
		ft_wrong_map_exit(map->data->lst_map, col_name,
			"Unauthorized re-definition");
	return (1);
}

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
	if (*colour < 0 || *colour > 255)
		return (1);
	return (0);
}

int	ft_check_floor(t_map_data *map, char **target, char *cmp)
{
	char	*tmp;
	int		rgb[3];
	int		i;

	(void)target;
	tmp = ft_strptr_to_str(&(map->flag_and_path[1]));
	map->flag_and_path = ft_free_strptr(map->flag_and_path);
	map->flag_and_path = ft_split(tmp, ',');
	free(tmp);
	tmp = NULL;
	if (ft_strptr_len(map->flag_and_path) != 3)
	{
		ft_free_strptr(map->flag_and_path);
		ft_wrong_map_exit(map->data->lst_map, cmp, ": not a valid colour");
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_check_value(map->flag_and_path[i], &rgb[i]) == 1)
			return (ft_wrong_map_exit(map->data->lst_map, cmp,
					": not a valid colour"), 1);
	}
	ft_check_redefinition(map, cmp, &(map->data->floor),
		ft_get_argb(0, rgb[0], rgb[1], rgb[2]));
	return (0);
}

int	ft_check_ceilling(t_map_data *map, char **target, char *cmp)
{
	char	*tmp;
	int		rgb[3];
	int		i;

	(void)target;
	tmp = ft_strptr_to_str(&(map->flag_and_path[1]));
	map->flag_and_path = ft_free_strptr(map->flag_and_path);
	map->flag_and_path = ft_split(tmp, ',');
	free(tmp);
	tmp = NULL;
	if (ft_strptr_len(map->flag_and_path) != 3)
	{
		ft_free_strptr(map->flag_and_path);
		ft_wrong_map_exit(map->data->lst_map, cmp, ": not a valid colour");
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_check_value(map->flag_and_path[i], &rgb[i]) == 1)
			return (ft_wrong_map_exit(map->data->lst_map, cmp,
					": not a valid colour"), 1);
	}
	ft_check_redefinition(map, cmp, &(map->data->ceilling),
		ft_get_argb(0, rgb[0], rgb[1], rgb[2]));
	return (0);
}
