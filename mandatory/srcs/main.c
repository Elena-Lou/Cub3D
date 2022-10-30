/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:30 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/30 17:44:23 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_data(t_cub_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->minimap.mlx_img = NULL;
	data->tex[0].path = NULL;
	data->tex[1].path = NULL;
	data->tex[2].path = NULL;
	data->tex[3].path = NULL;
	data->ceiling = -1;
	data->floor = -1;
	data->lst_map = NULL;
	data->grid = NULL;
	data->map_height = 0;
	data->map_width = 0;
	data->player.move_x = 0;
	data->player.move_y = 0;
	data->player.rotate = 0;
}

static void	ft_keypress_hook(t_cub_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, ft_key_press_check, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, ft_key_release_check,
		data);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, ft_close_window, data);
}

int	main(int ac, char **av)
{
	t_cub_data	data;

	if (ac != 2)
	{
		printf("Usage : %s maps/[map name].cub\n", av[0]);
		return (1);
	}
	ft_init_data(&data);
	if (ft_map_to_list(&data, av[1]))
		return (1);
	ft_check_map_content(&data);
	if (ft_window_init(&data))
		return (ft_lstclear(&(data.lst_map), ft_clear_map), 1);
	ft_set_texture(&data);
	ft_render_minimap(&data);
	ft_set_ray_data(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.img.mlx_img, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
		data.minimap.mlx_img, 5, 640);
	ft_keypress_hook(&data);
	mlx_loop_hook(data.mlx_ptr, ft_render_img, &data);
	mlx_loop(data.mlx_ptr);
	ft_lstclear(&(data.lst_map), ft_clear_map);
	return (0);
}
