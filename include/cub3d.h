/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/05 17:11:12 by aweaver          ###   ########.fr       */
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

/*
** DEFINES
*/

/* MAP_TO_LIST */

# ifndef WRONG_MAP_NAME
#  define WRONG_MAP_NAME 1
# endif

# ifndef WRONG_MALLOC
#  define WRONG_MALLOC 1
# endif

/* XPM */
# ifndef NOT_XPM
#  define NOT_XPM 1
# endif

# ifndef NOT_FOUND
#  define NOT_FOUND 2
# endif

# ifndef DEBUG
#  define DEBUG 1
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

typedef struct s_player
{
	int			x;
	int			y;
}			t_player;

typedef struct s_cub_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}			t_cub_img;

typedef struct s_cub_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	int			ceilling;
	int			floor;
	char		**grid;
	t_list		*lst_map;
	t_cub_img	img;
	t_player	player;
}				t_cub_data;

typedef struct s_map_data
{
	char		*line;
	char		**flag_and_path;
	t_cub_data	*data;
}				t_map_data;

/*
**	FUNCTION POINTERS
*/

typedef int	(*t_check)(t_map_data *map);

int		ft_check_no(t_map_data *map);
int		ft_check_so(t_map_data *map);
int		ft_check_ea(t_map_data *map);
int		ft_check_we(t_map_data *map);
int		ft_check_floor(t_map_data *map);
int		ft_check_ceilling(t_map_data *map);

/*
**	MAIN.C
*/

void	ft_init_player(t_cub_data *data);
int		ft_key_check(int key, t_cub_data *data);

/*
**	MAP_CHECK.C
*/

int		ft_add_line_map(char *line, t_cub_data *data);
int		ft_map_to_list(t_cub_data *data, char *map_file);
void	ft_check_map_content(t_cub_data *data);
int		ft_check_name(char *map_name);

/*
** CHECK_MAP_GRID.C
*/

int		ft_create_map_grid(t_cub_data *data);
int		ft_check_map_grid(t_cub_data *data, char **grid);

/*
** FREE_FUNCTIONS.C
*/

void	ft_clear_map(void *list_elem);
void	ft_clear_data(t_cub_data *data);

/*
** ERROR_MESSAGE.C
*/

void	ft_wrong_map_exit(t_list *list, char *texture, char *error_msg);
int		ft_err_msg(char *str);
void	ft_exit_check_grid(t_cub_data *data, char *error_msg);

/*
**	IMAGE_UTILS.C
*/

void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour);
void	ft_render_player(t_cub_data *data, int colour);
void	ft_render_background(t_cub_data *data, int colour);
int		ft_render_img(t_cub_data *data);
int		ft_window_init(t_cub_data *data);
int		ft_close_window(t_cub_data *data);

#endif