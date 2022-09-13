/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/14 10:18:34 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		close_window(data);
	else
		printf("%d\n", key);
	return (0);
}

int	close_window(t_cub_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
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
	map_to_list(&data, av[1]);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 800, "Cub3D");
	if (!data.win_ptr)
		return (1);
	
	mlx_key_hook(data.win_ptr, &key_check, &data);
	mlx_hook(data.win_ptr, 17, 1L << 3, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
