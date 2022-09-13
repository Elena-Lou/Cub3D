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

#############################################################################
#								FILES										#
#############################################################################

SRCS	=	main.c \
			$(addprefix parsing/, \
				map_check.c\
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

$(NAME): $(OBJS) $(LIBFT)
		@make $(SILENT) -C ./minilibx/ all
		@echo "$(CYAN)\nMiniLibX $(PURPLE)compiled\n$(NO_COLOUR)"
		#$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS) $(LIBFT) minilibx/libmlx_Linux.a -lm -lbsd -lX11 -lXext
		$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCS) $(LIBFT) $(MLX) -lm -lbsd -lX11 -lXext
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
		./$(NAME) maps/default.cub

vtest:	all
		valgrind --leak-check=full -s ./$(NAME) maps/default.cub

-include $(DEPS)

.PHONY: all clean fclean re test vtest
