/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:29:35 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:30:03 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_minimap_borders(t_cub_data *data, int colour)
{
	int	size;
	int	x;
	int	y;

	y = 0;
	size = MMAP_SIZE + (MMAP_SIZE / (2 * MMAP_FOG));
	while (y < size)
	{
		x = -1;
		while (++x <= size)
		{
			if (x < MMAP_BORDER_SIZE || x > size - MMAP_BORDER_SIZE
				|| y < MMAP_BORDER_SIZE || y > size - MMAP_BORDER_SIZE)
				ft_put_pix_img(&data->minimap, x, y, colour);
		}
		y++;
	}
}

void	ft_print_minimap_pixel(t_cub_data *data, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < (MMAP_SIZE / (2 * MMAP_FOG)))
	{
		j = 0;
		while (j < (MMAP_SIZE / (2 * MMAP_FOG)))
		{
			ft_put_pix_img(&data->minimap, (x + j), (y + i), colour);
			j++;
		}
		i++;
	}
}

void	ft_print_minimap(t_cub_data *data, char minimap[(MMAP_FOG *2) + 2]
[(MMAP_FOG *2) + 2], int x, int y)
{
	while (++y < ((MMAP_FOG * 2) + 1))
	{
		x = -1;
		while (++x < ((MMAP_FOG * 2) + 1))
		{
			if (minimap[y][x] == '\0')
				break ;
			if (minimap[y][x] == 'P')
				ft_print_minimap_pixel(data, (x * (MMAP_SIZE / (2 * MMAP_FOG))),
					(y * (MMAP_SIZE / (2 * MMAP_FOG))), 0x00ff00);
			else if (minimap[y][x] == '1')
				ft_print_minimap_pixel(data, (x * (MMAP_SIZE / (2 * MMAP_FOG))),
					(y * (MMAP_SIZE / (2 * MMAP_FOG))), 0x012354d);
			else if (minimap[y][x] == '0')
				ft_print_minimap_pixel(data, (x * (MMAP_SIZE / (2 * MMAP_FOG))),
					(y * (MMAP_SIZE / (2 * MMAP_FOG))), 0xefefef);
			else if (minimap[y][x] == ' ')
				ft_print_minimap_pixel(data, (x * (MMAP_SIZE / (2 * MMAP_FOG))),
					(y * (MMAP_SIZE / (2 * MMAP_FOG))), 0x000000);
		}
		x = 0;
	}
}
