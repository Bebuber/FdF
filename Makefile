# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 16:25:10 by bebuber           #+#    #+#              #
#    Updated: 2024/06/16 17:33:15 by bebuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

LIBFT	= libft/libft.a
LIBMLX	= ./minilibx_macos
LIBS	= $(LIBMLX)/libmlx.a -framework OpenGL -framework AppKit

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Wunreachable-code
RM		= rm -rf

SRCS	= main.c read_file.c draw.c error.c
OBJS	= $(SRCS:.c=.o)

all: libmlx $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LIBFT) $(LIBS) $(OBJS) -o $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)
	make -C $(LIBMLX)/build -j4

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft
	$(RM) $(LIBMLX)/build

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx