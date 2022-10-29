/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:21:47 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/28 16:22:18 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_texture(t_cub_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->tex[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->tex[i].path,
				&data->tex[i].width,
				&data->tex[i].height);
		if (data->tex[i].img == NULL)
		{
			while (--i > 0)
				mlx_destroy_image(data->mlx_ptr, data->tex[i].img);
			ft_wrong_map_exit(data->lst_map, "Texture: ", "Incorrect.");
		}
		i++;
	}
}
