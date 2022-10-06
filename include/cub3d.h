/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/17 11:47:49 by aweaver          ###   ########.fr       */
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
# include <math.h>
# include <limits.h>

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

# ifndef PI
#  define PI 3.14159265359
# endif

# ifndef FOV
#  define FOV 1.151917306
# endif

# ifndef EAST
#  define EAST 0
# endif

# ifndef NORTH
#  define NORTH 4.71238898
# endif

# ifndef WEST
#  define WEST 3.14159265359
# endif

# ifndef SOUTH
#  define SOUTH 1.570796327
# endif

# ifndef LEFT_ARROW
#  define LEFT_ARROW 65361
# endif

# ifndef RIGHT_ARROW
#  define RIGHT_ARROW 65363
# endif

# ifndef MMAP_SIZE
#  define MMAP_SIZE 128
# endif

# ifndef MMAP_FOG
#  define MMAP_FOG 4
# endif

# ifndef MMAP_BORDER_SIZE
#  define MMAP_BORDER_SIZE 5
# endif

# ifndef RAYS_NB
#  define RAYS_NB 1000
# endif

# ifndef FALSE
#  define FALSE 1
# endif

# ifndef TRUE
#  define TRUE 0
# endif

typedef struct s_dda
{
	double	d_x;
	double	d_y;
	double	step_x;
	double	step_y;
	double	inter_x;
	double	inter_y;
	double	pos_x;
	double	pos_y;
	int		dir_x;
	int		dir_y;
	double	theta;
	int		hit_x;
	int		hit_y;
	int		hzt_x;
	int		hzt_y;
	int		vrt_x;
	int		vrt_y;
	double	distance;
	int		hzt_hit;
	int		vrt_hit;
	int		facing_up;
	int		facing_left;
	double	tan_theta;
	double	hzt_dist;
	double	vrt_dist;
	int		id;
}			t_dda;

typedef struct s_player
{
	int			x;
	int			y;
	double		pov;
	int			tile_x;
	int			tile_y;
	int			dir_x;
	int			dir_y;
	double		dist_pp;
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
	int			map_height;
	int			map_width;
	t_list		*lst_map;
	t_cub_img	img;
	t_cub_img	minimap;
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

void	ft_create_minimap(t_cub_data *data);
void	ft_render_minimap(t_cub_data *data, int colour);
void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour);
void	ft_render_player(t_cub_data *data, int colour);
void	ft_render_background(t_cub_data *data, int colour);
int		ft_render_img(t_cub_data *data);
int		ft_window_init(t_cub_data *data);
int		ft_close_window(t_cub_data *data);

/*
** DDA.C
*/

void	ft_set_ray_data(t_cub_data *data);
void	ft_distance_to_projection_plane(t_player *player);
void	ft_cast_ray(t_dda *ray, t_cub_data *data);
void	ft_hzt_intersections(t_cub_data *data, t_dda *ray);
void	ft_vrt_intersections(t_cub_data *data, t_dda *ray);
double	ft_normalize_angle(double theta);
void	ft_set_dir(t_dda *ray);
double	ft_dist_btw_pts(double player_x, double player_y, double hit_x, double hit_y);

/*
** PLAYER_MOVEMENT.C
*/

int		ft_move_forward(t_cub_data *data);
int		ft_move_backward(t_cub_data *data);
int		ft_strafe_left(t_cub_data *data);
int		ft_strafe_right(t_cub_data *data);
int		ft_rotate_left(t_cub_data *data);
int		ft_rotate_right(t_cub_data *data);

/*
** MINIMAP.C
*/

void	ft_create_minimap(t_cub_data *data);
int		ft_get_player_offset_y(t_cub_data *data, int py);
int		ft_get_player_offset_x(t_cub_data *data, int px);
void	ft_fill_minimap(char minimap[(MMAP_FOG*2) + 2][(MMAP_FOG *2) + 2],
			t_cub_data *data, int offset_x, int offset_y);

/*
** PRINT_MINIMAP.C
*/

void	ft_print_minimap(t_cub_data *data, char minimap[(MMAP_FOG *2) + 2]
		[(MMAP_FOG *2) + 2], int x, int y);
void	ft_print_minimap_pixel(t_cub_data *data, int x, int y, int colour);
void	ft_render_minimap_borders(t_cub_data *data, int colour);
#endif
