/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:31:41 by aweaver           #+#    #+#             */
/*   Updated: 2022/09/19 11:32:00 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_floor(t_cub_data *data, char *line)
{
	(void)data;
	printf("floor line = %s\n", line);
	return (0);
}

int	ft_check_ceilling(t_cub_data *data, char *line)
{
	(void)data;
	printf("ceilling line = %s\n", line);
	return (0);
}
