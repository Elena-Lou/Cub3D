NAME = cub3D


#############################################################################
#							COMPILATION										#
#############################################################################

CC	=	cc

CFLAGS		=	-Wall -Wextra -Werror -g3
DEPSFLAGS	=	-MMD -MF $(@:.o=.d)

INCS		=	-I include\
				-I libft/include\
				-I minilibx

RM			=	rm -rf
SILENT		=	--no-print-directory -s

VALGRIND	=	valgrind --leak-check=full --show-leak-kinds=all

#############################################################################
#							LIBRARIES										#
#############################################################################

MLX_PATH	=	minilibx/
MLX			=	$(addprefix $(MLX_PATH), libmlx_Linux.a)

LIBFT_PATH	=	libft/
LIBFT		=	$(addprefix $(LIBFT_PATH), libft.a)

LIBS		=	-lm -lbsd -lX11 -lXext

#############################################################################
#								FILES										#
#############################################################################

SRCS	=		main \
				$(addprefix parsing/, \
					map_to_list\
					check_map_content\
					check_map_name\
					check_wall_texture_functions\
					check_ceilling_floor_texture_functions\
					create_map_grid\
					check_map_grid\
					check_tile\
				)\
				$(addprefix utils/, \
					free_functions\
					error_message\
				)\
				$(addprefix image/, \
					image_utils\
					window_utils\
					rendition\
					minimap\
					print_minimap\
					)\
				$(addprefix movement/, \
					player_movement\
					player_rotation\
					key_checks\
					update_tile\
				)\
				$(addprefix raycasting/, \
					dda\
					dda_maths\
					dda_rays\
					wall_projection\
				)\
				$(addprefix textures/, \
					apply_textures\
					pick_colours\
					set_textures\
				)\

#SRCS_B	=	$(addprefix bonus/, \
#				main_bonus.c \
#				$(addprefix parsing/, \
#					map_to_list_bonus.c\
#					check_map_content_bonus.c\
#					check_map_name_bonus.c\
#					check_wall_texture_functions_bonus.c\
#					check_ceilling_floor_texture_functions_bonus.c\
#					create_map_grid_bonus.c\
#					check_map_grid_bonus.c\
#					check_tile_bonus.c\
#				)\
#				$(addprefix utils/, \
#					free_functions_bonus.c\
#					error_message_bonus.c\
#				)\
#				$(addprefix image/, \
#					image_utils_bonus.c\
#					window_utils_bonus.c\
#					rendition_bonus.c\
#					minimap_bonus.c\
#					print_minimap_bonus.c\
#					)\
#				$(addprefix movement/, \
#					player_movement_bonus.c\
#					player_rotation_bonus.c\
#					key_checks_bonus.c\
#					update_tile_bonus.c\
#				)\
#				$(addprefix raycasting/, \
#					dda_bonus.c\
#					dda_maths_bonus.c\
#					dda_rays_bonus.c\
#					wall_projection_bonus.c\
#				)\
#				$(addprefix textures/, \
#					apply_textures_bonus.c\
#					pick_colours_bonus.c\
#					set_textures_bonus.c\
#				)\
#			)

SRCS_BONUS = $(addsuffix _bonus.c , $(SRCS))
SRCS_DIR = ./srcs/

OBJS_DIR = ./objs/

OBJS = $(addsuffix .o, $(addprefix $(OBJS_DIR), $(SRCS)))
OBJS_BONUS = $(addsuffix _bonus.o, $(addprefix $(OBJS_DIR), $(SRCS)))

DEPS = $(OBJS:.o=.d)
DEPS_BONUS = $(OBJS_BONUS:.o=.d)

#############################################################################
#							COLOURS											#
#############################################################################

PURPLE		= \033[1;35m
CYAN		= \033[1;36m
GREEN		= \033[1;32m
ORANGE		= \033[1;33m
NO_COLOUR	= \033[m

#############################################################################
#							RULES											#
#############################################################################

all: $(NAME)
	@make $(NAME) -q && echo "$(GREEN)All Good Here !$(NO_COLOUR)"

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $< $(DEPSFLAGS) $(INCS)

$(LIBFT):
		@make $(SILENT) -C ./libft/ all
		@echo "$(PURPLE)\nLibft $(CYAN)compiled\n$(NO_COLOUR)"

$(MLX):
		@make $(SILENT) -C ./minilibx/ all
		@echo "$(CYAN)\nMiniLibX $(PURPLE)compiled\n$(NO_COLOUR)"

bonus:	$(OBJS_BONUS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@ $(INCS) $(LIBFT) minilibx/libmlx_Linux.a $(LIBS)
			@echo "$(ORANGE)cub3D$(CYAN) is ready$(NO_COLOUR)"

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS) $(LIBFT) minilibx/libmlx_Linux.a $(LIBS)
		@echo "$(ORANGE)cub3D$(CYAN) is ready$(NO_COLOUR)"

clean:
		@make $(SILENT) -C $(LIBFT_PATH) clean
		@make $(SILENT) -C $(MLX_PATH) clean
		$(RM) $(OBJS_DIR)

fclean: clean
		$(RM) minilibx/libmlx.a
		$(RM) $(NAME)
		@make $(SILENT) -C $(LIBFT_PATH) fclean
		@rm -f $(MLX)

re:		fclean
		@make $(SILENT) all

test:	all
		./$(NAME) maps/small.cub

vtest:	all
		$(VALGRIND) ./$(NAME) maps/default_north.cub

-include $(DEPS)

.PHONY: all clean fclean re test vtest bonus
