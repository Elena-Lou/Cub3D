/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/09/07 15:57:57 by elouisia         ###   ########.fr       */
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
    void    *mlx_ptr;
    void    *win_ptr;
}   t_cub_data;

int    key_check(int key, t_cub_data *data);
int	close_window(t_cub_data *data);

#endif