/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:06:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/26 08:46:10 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_header(void *arg)
{
	t_map_data			*map;
	const char			*comp[] = {"NO", "SO", "EA", "WE", "F", "C"};
	const t_check		ft_check[] = {&ft_check_texture, &ft_check_texture,
		&ft_check_texture, &ft_check_texture, &ft_check_floor,
		&ft_check_ceilling};
	int					i;

	i = 0;
	map = (t_map_data *)arg;
	if (map->flag_and_path == NULL || *(map->flag_and_path) == NULL)
		return ;
	while (i < 6)
	{
		if (ft_strcmp(*map->flag_and_path, comp[i]) == 0)
		{
			ft_check[i](map, &map->data->tex[i].path, (char *)comp[i]);
			return ;
		}
		i++;
	}
}

void	ft_tokenise_map(void *arg)
{
	t_map_data	*map_data;

	if (arg == NULL)
		return ;
	map_data = (t_map_data *)arg;
	map_data->flag_and_path = ft_split_f(map_data->line, &ft_iswhitespace);
	if (*map_data->flag_and_path && (**map_data->flag_and_path == '0'
			|| **map_data->flag_and_path == '1'))
		map_data->flag_and_path = ft_free_strptr(map_data->flag_and_path);
}

void	ft_check_texture_all_set(t_cub_data *data)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (data->tex[i].path == NULL)
			ft_wrong_map_exit(data->lst_map, "Texture: ", "not set.");
		i++;
	}
	if (data->floor == -1)
		ft_wrong_map_exit(data->lst_map, "Floor: ", "not set.");
	else if (data->ceilling == -1)
		ft_wrong_map_exit(data->lst_map, "Ceilling: ", "not set.");
}

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

void	ft_check_map_content(t_cub_data *data)
{
	ft_lstiter(data->lst_map, &ft_tokenise_map);
	ft_lstiter(data->lst_map, &ft_check_map_header);
	ft_check_texture_all_set(data);
	ft_set_texture(data);
	ft_create_map_grid(data);
	ft_check_map_grid(data, data->grid);
	data->map_width = ft_strlen_int(*data->grid);
	data->map_height = ft_strptr_len(data->grid);
}
