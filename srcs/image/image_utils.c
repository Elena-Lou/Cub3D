/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:53:05 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/22 16:39:00 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_background(t_cub_data *data, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pix_img(&data->img, x, y, colour);
			x++;
		}
		y++;
	}
}

void	ft_render_player(t_cub_data *data, int colour)
{
	int	i;
	int	j;

	i = data->player.y;
	while (i < data->player.y + 10)
	{
		j = data->player.x;
		while (j < data->player.x + 10)
		{
			ft_put_pix_img(&data->img, j, i, colour);
			j++;
		}
		i++;
	}
}

int	ft_render_img(t_cub_data *data)
{
	ft_render_background(data, 0xA9A9A9);
	ft_render_player(data, 0x8E1600);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x *(img->bpp / 8));
	*(int *)pixel = colour;
}

int	ft_window_init(t_cub_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_ptr)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.mlx_img)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

int	ft_close_window(t_cub_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_lstclear(&(data->lst_map), ft_clear_map);
	exit (0);
}
