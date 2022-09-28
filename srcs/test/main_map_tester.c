/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/28 10:54:08 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_cub_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->ceilling = -1;
	data->floor = -1;
	data->lst_map = NULL;
}

int	main(int ac, char **av)
{
	t_cub_data	data;

	if (ac != 2)
	{
		printf("Usage : ./cub2D map.cub\n");
		return (1);
	}
	ft_init_data(&data);
	if (map_to_list(&data, av[1]))
		return (0);
	ft_check_map_content(&data);
	printf("Main would have started a mlx window\n");
	ft_lstclear(&(data.lst_map), ft_clear_map);
	return (0);
}
