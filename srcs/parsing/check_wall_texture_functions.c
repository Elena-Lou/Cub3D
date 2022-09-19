/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_texture_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:24 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 15:39:11 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_no(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("no flag = %s\n", *flag_and_path);
	printf("no path = %s\n", (*flag_and_path + 1));
	return (0);
}

int	ft_check_so(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("so flag = %s\n", *flag_and_path);
	printf("so path = %s\n", (*flag_and_path + 1));
	return (0);
}

int	ft_check_ea(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("ea flag = %s\n", *flag_and_path);
	printf("ea path = %s\n", (*flag_and_path + 1));
	return (0);
}

int	ft_check_we(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("we flag = %s\n", *flag_and_path);
	printf("we path = %s\n", (*flag_and_path + 1));
	return (0);
}
