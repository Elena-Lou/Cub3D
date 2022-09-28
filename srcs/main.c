/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/28 09:35:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_check(int key, t_cub_data *data)
{
	if (key == XK_Escape)
		ft_close_window(data);
	else
		printf("%d\n", key);
	return (0);
}

int	ft_close_window(t_cub_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_lstclear(&(data->lst_map), ft_clear_map);
	exit (0);
}

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
	ft_map_to_list(&data, av[1]);
	ft_check_map_content(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (ft_lstclear(&(data.lst_map), ft_clear_map), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1000, 800, "Cub3D");
	if (!data.win_ptr)
		return (ft_lstclear(&(data.lst_map), ft_clear_map), 1);
	mlx_key_hook(data.win_ptr, &ft_key_check, &data);
	mlx_hook(data.win_ptr, 17, 1L << 3, &ft_close_window, &data);
	mlx_loop(data.mlx_ptr);
	ft_lstclear(&(data.lst_map), ft_clear_map);
	return (0);
}
