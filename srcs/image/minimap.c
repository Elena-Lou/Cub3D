/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:42:27 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/13 17:12:02 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_player_offset_x(t_cub_data *data, int px)
{
	int	size;

	size = ft_strlen_int(*data->grid);
	if (px <= MMAP_FOG)
		return (0);
	if (px >= MMAP_FOG && size - px > MMAP_FOG + 1)
		return (px - MMAP_FOG);
	if (px >= MMAP_FOG && size - px <= MMAP_FOG + 1)
		return (size - ((2 * MMAP_FOG) + 2));
	return (0);
}

int	ft_get_player_offset_y(t_cub_data *data, int py)
{
	int	size;

	size = ft_strptr_len(data->grid);
	if (py <= MMAP_FOG)
		return (0);
	if (py >= MMAP_FOG && size - py > MMAP_FOG + 1)
		return (py - MMAP_FOG);
	if (py >= MMAP_FOG && size - py <= MMAP_FOG + 1)
		return (size - ((2 * MMAP_FOG) + 1));
	return (0);
}

void	ft_fill_minimap(char minimap[(MMAP_FOG*2) + 2][(MMAP_FOG *2) + 2]
, t_cub_data *data, int offset_x, int offset_y)
{
	int	map_width;
	int	x;
	int	y;

	map_width = ft_strlen_int(*data->grid);
	y = -1;
	while (++y < ((MMAP_FOG * 2) + 1) && y < ft_strptr_len(data->grid))
	{
		x = -1;
		while (++x < ((MMAP_FOG * 2) + 1) && x < map_width)
		{
			if (data->player.x >> 6 == (x + offset_x) && data->player.y >> 6
				== (y + offset_y))
				minimap[y][x] = 'P';
			else if (data->grid[offset_y + y][offset_x + x] == '1')
				minimap[y][x] = '1';
			else if (data->grid[offset_y + y][offset_x + x] == ' ')
				minimap[y][x] = ' ';
			else
				minimap[y][x] = '0';
		}
		minimap[y][x] = '\0';
	}
	minimap[y][0] = '\0';
}

void	ft_render_minimap(t_cub_data *data)
{
	char	minimap[(MMAP_FOG * 2) + 2][(MMAP_FOG * 2) + 2];
	int		offset_x;
	int		offset_y;

	offset_x = ft_get_player_offset_x(data, data->player.x >> 6);
	offset_y = ft_get_player_offset_y(data, data->player.y >> 6);
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr, MMAP_SIZE
			+ (MMAP_SIZE / (2 * MMAP_FOG)), MMAP_SIZE + MMAP_SIZE
			/ (2 * MMAP_FOG));
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	ft_fill_minimap(minimap, data, offset_x, offset_y);
	ft_print_minimap(data, minimap, 0, -1);
	ft_print_minimap_borders(data, 0x2874A6);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->minimap.mlx_img, 5, 640);
	mlx_destroy_image(data->mlx_ptr, data->minimap.mlx_img);
}
