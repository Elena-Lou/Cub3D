/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceilling_floor_texture_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:41 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 15:37:30 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_floor(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("floor flag = %s\n", *flag_and_path);
	printf("floor path = %s\n", (*flag_and_path + 1));
	return (0);
}

int	ft_check_ceilling(t_cub_data *data, char **flag_and_path)
{
	(void)data;
	printf("ceilling flag = %s\n", *flag_and_path);
	printf("ceilling path = %s\n", (*flag_and_path + 1));
	return (0);
}
