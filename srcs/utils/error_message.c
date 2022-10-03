/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:15 by aweaver           #+#    #+#             */
/*   Updated: 2022/10/03 13:28:29 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_err_msg(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_wrong_map_exit(t_list *list, char *texture, char *error_msg)
{
	t_map_data	*map;
	t_cub_data	*data;

	map = (t_map_data *)list->content;
	data = map->data;
	ft_clear_data(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(texture, 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_exit_check_grid(t_cub_data *data, char *error_msg)
{
	ft_free_strptr(data->grid);
	ft_lstclear(&(data->lst_map), ft_clear_map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}
