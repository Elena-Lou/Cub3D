SRCS	=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_iswhitespace.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strdup.c \
			ft_bzero.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_itoa.c \
			ft_split.c \
			ft_split_f.c \
			ft_printf.c \
			ft_printf_n.c \
			ft_printf_base.c \
			ft_printf_utils.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstiter.c \
			ft_lstsize.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstmap.c\
			ft_free_strptr.c\
			ft_strjoin_free.c\
			ft_strcpy.c\
			ft_strlen_nl.c\
			ft_strcat.c\
			ft_strlen_int.c\
			ft_strptr_to_str.c\
			ft_strptr_len.c

OBJS_DIR = objs

OBJS	= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

DEPS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

DEPSFLAGS	= -MMD -MF $(@:.o=.d)

INCS		= -I include

RM	= rm -rf

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= libft.a

all:	${NAME}

$(OBJS_DIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< $(DEPSFLAGS) $(INCS)

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS_DIR} ${DEPS}

fclean: clean
	${RM} ${NAME}

re: fclean
	@make -s all

-include $(DEPS)

.PHONY: all clean fclean re