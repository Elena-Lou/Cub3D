/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:54:20 by elouisia          #+#    #+#             */
/*   Updated: 2022/10/28 19:23:31 by aweaver          ###   ########.fr       */
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
#  define EAST 0.0
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

# ifndef FALSE
#  define FALSE 1
# endif

# ifndef TRUE
#  define TRUE 0
# endif

# ifndef NO
#  define NO 0
# endif

# ifndef SO
#  define SO 1
# endif

# ifndef EA
#  define EA 2
# endif

# ifndef WE
#  define WE 3
# endif

# ifndef TEX_SIZE
#  define TEX_SIZE 64
# endif

typedef struct s_dda
{
	double	step_x;
	double	step_y;
	double	inter_x;
	double	inter_y;
	double	theta;
	double	dir_x;
	double	dir_y;
	double	hzt_x;
	double	hzt_y;
	double	vrt_x;
	double	vrt_y;
	double	distance;
	double	hzt_hit;
	double	vrt_hit;
	double	facing_up;
	double	facing_left;
	double	tan_theta;
	double	hzt_dist;
	double	vrt_dist;
	double	strip_height;
	int		id;
}			t_dda;

typedef struct s_player
{
	double		x;
	double		y;
	double		pov;
	int			tile_x;
	int			tile_y;
	int			dir_x;
	int			dir_y;
	double		dist_pp;
	int			move_x;
	int			move_y;
	int			rotate;
}			t_player;

typedef struct s_cub_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}			t_cub_img;

typedef struct s_texture
{
	void		*img;
	char		*path;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

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
	t_texture	tex[4];
	t_player	player;
}				t_cub_data;

typedef struct s_map_data
{
	char		*line;
	char		**flag_and_path;
	t_cub_data	*data;
}				t_map_data;

int		ft_check_texture(t_map_data *map, char **target, char *cmp);
int		ft_check_floor_ceilling(t_map_data *map, int *target, char *cmp);

/*
**	MAIN.C
*/

void	ft_init_player(t_cub_data *data);
int		ft_key_press_check(int key, t_cub_data *data);
int		ft_key_release_check(int key, t_cub_data *data);

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
void	ft_check_map_grid(t_cub_data *data, char **grid);

/*
** CHECK_TILE.C
*/

int		ft_is_void(char c);

/*
** FREE_FUNCTIONS.C
*/

void	ft_clear_data_no_tex(t_cub_data *data);
void	ft_clear_data(t_cub_data *data);
void	ft_clear_map(void *list_elem);

/*
** ERROR_MESSAGE.C
*/

void	ft_wrong_map_exit(t_list *list, char *texture, char *error_msg);
int		ft_err_msg(char *str);
void	ft_exit_check_grid(t_cub_data *data, char *error_msg);

/*
**	IMAGE_UTILS.C
*/

void	ft_draw_line(t_cub_data *data, double angle, double len, int colour);
void	ft_render_minimap(t_cub_data *data);
void	ft_put_pix_img(t_cub_img *img, int x, int y, int colour);
void	ft_render_player(t_cub_data *data, int colour);
void	ft_render_background(t_cub_data *data, int colour);
int		ft_render_img(t_cub_data *data);
int		ft_window_init(t_cub_data *data);
int		ft_close_window(t_cub_data *data);

/*
** DDA.C
*/

void	ft_set_closest_distance(t_dda *ray);
void	ft_set_ray_data(t_cub_data *data);
void	ft_distance_to_projection_plane(t_player *player);
void	ft_cast_ray(t_cub_data *data, t_dda *ray);
void	ft_hzt_intersections(t_cub_data *data, t_dda *ray);
void	ft_vrt_intersections(t_cub_data *data, t_dda *ray);
double	ft_normalise_angle(double theta);
void	ft_set_dir(t_dda *ray);
double	ft_dist_btw_pts(double plr_x, double plr_y, double hit_x, double hit_y);
void	ft_wall_scaling(t_cub_data *data, t_dda *ray);
void	ft_wall_projection(t_cub_data *data, t_dda *ray);

/*
** PLAYER_MOVEMENT.C
*/

int		ft_move(t_cub_data *data, int *moved);
int		ft_is_valid_move(t_cub_data *data, int x, int y);
int		ft_move_forward(t_cub_data *data);
int		ft_move_backward(t_cub_data *data);
int		ft_strafe_left(t_cub_data *data);
int		ft_strafe_right(t_cub_data *data);
int		ft_rotate_left(t_cub_data *data);
int		ft_rotate_right(t_cub_data *data);

/*
** UPDATE_TILE.C
*/

void	ft_update_player_tile(t_cub_data *data, int tile_x, int tile_y);

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
void	ft_print_minimap_borders(t_cub_data *data, int colour);

/*
**	APPLY_TEXTURES.C
*/

void	ft_render_wall(t_cub_data *data, int top, int bottom, t_dda *ray);
int		ft_texture_x_offset(t_dda *ray);
int		ft_texture_y_offset(t_dda *ray, int y, int tex_height);
void	ft_init_textures(t_cub_data *data);

/*
**	SET_TEXTURES.C
*/

void	ft_set_texture(t_cub_data *data);

/*
** PICK_COLOURS.C
*/

int		ft_pick_colour(t_cub_data *data, t_dda *ray, int y, int x_offset);
#endif
