/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/02 15:55:21 by elouisia         ###   ########.fr       */
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
	data->grid = NULL;
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
	if (ft_window_init(&data))
		return (ft_lstclear(&(data.lst_map), ft_clear_map), 1);
	ft_init_player(&data);
	ft_render_img(&data);
	mlx_key_hook(data.win_ptr, &ft_key_check, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, &ft_close_window, &data);
	mlx_loop(data.mlx_ptr);
	ft_lstclear(&(data.lst_map), ft_clear_map);
	return (0);
}
