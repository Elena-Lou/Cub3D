/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:53:05 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/29 11:15:56 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x *(img->bpp / 8));
	*(int *)pixel = colour;
}
