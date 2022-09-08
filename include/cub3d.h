/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/08 18:04:47 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <errno.h>

typedef struct s_cub_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
}	t_cub_data;

/*
**	MAIN.C
*/

int	key_check(int key, t_cub_data *data);
int	close_window(t_cub_data *data);

/*
**	MAP_CHECK.C
*/

int	check_map(t_cub_data *data, char *map_file);

#endif