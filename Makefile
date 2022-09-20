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

SRCS	=	main.c \
			$(addprefix parsing/, \
				map_to_list.c\
				check_map_content.c\
				check_map_name.c\
				check_wall_texture_functions.c\
				check_ceilling_floor_texture_functions.c\
			)\
			$(addprefix utils/, \
				free_functions.c\
			)

SRCS_DIR = ./srcs/

OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

DEPS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.d))




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

test:	re
		./$(NAME) maps/default.cub

vtest:	re
		valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) maps/default.cub

test_map:	$(LIBFT) $(MLX)
		$(CC) $(CFLAGS) srcs/tests/main_test_map.c srcs/parsing/map_check.c srcs/parsing/map_check_content.c $(LIBFT) $(MLX) $(LIBS) -o $(NAME) $(INCS)
		./.test_maps.sh

-include $(DEPS)

.PHONY: all clean fclean re test vtest test_map
