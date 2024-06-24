# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:25:10 by bebuber           #+#    #+#              #
#    Updated: 2024/06/24 15:36:44 by bebuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME	= fdf

LIBFT	= libft/libft.a
LIBMLX	= minilibx_macos/libmlx.a
LIBS	=$(LIBMLX) -framework OpenGL -framework AppKit 

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code
RM		= rm -rf

SRCS	= main.c read_file.c draw.c error.c read_file_utils.c key_hook.c draw_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(LIBS) $(OBJS) -o $(NAME)
	echo "==>	Fdf compiled!"

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx