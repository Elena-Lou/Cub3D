/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:02:11 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/29 16:03:22 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x *(img->bpp / 8));
	*(int *)pixel = colour;
}
