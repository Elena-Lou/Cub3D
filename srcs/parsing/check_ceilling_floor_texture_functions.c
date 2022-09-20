/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor_texture_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:41 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/20 12:16:18 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_floor(t_map_data *map)
{
	printf("floor flag = %s\n", *map->flag_and_path);
	printf("floor path = %s\n", (*(map->flag_and_path + 1)));
	return (0);
}

int	ft_check_ceilling(t_map_data *map)
{
	printf("ceilling flag = %s\n", *map->flag_and_path);
	printf("ceilling path = %s\n", (*(map->flag_and_path + 1)));
	return (0);
}
