/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/16 14:42:18 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_show_parsed_input(t_cub_data *data)
{
	printf("NORTH = %s\n", data->no);
	printf("SOUTH = %s\n", data->so);
	printf("EAST  = %s\n", data->ea);
	printf("WEST  = %s\n", data->we);
	printf("ceilling colour = %d\n", data->ceilling);
	printf("floor colour = %d\n", data->floor);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub_data	data;

	if (ac != 2)
	{
		printf("Usage : ./cub2D map.cub\n");
		return (1);
	}
	data.lst_map = NULL;
	if (map_to_list(&data, av[1]))
		return (1);
	ft_show_parsed_input(&data);
	return (0);
}
