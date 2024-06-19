# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:25:10 by bebuber           #+#    #+#              #
#    Updated: 2024/06/17 21:05:40 by bebuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME	= fdf

LIBFT	= libft/libft.a
LIBMLX	= ./minilibx_macos/libmlx.a
LIBS	= $(LIBMLX) -framework OpenGL -framework AppKit

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code
RM		= rm -rf

SRCS	= main.c read_file.c draw.c error.c read_file_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(LIBS) $(OBJS) -o $(NAME)
	echo '\033[0;32m'"==>	Fdf compiled!"

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx