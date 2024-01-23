# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasarov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:59:56 by mmasarov          #+#    #+#              #
#    Updated: 2024/01/23 15:59:58 by mmasarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = fractol.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_NAME = mlx
MLX = $(MLX_PATH)$(MLX_NAME)

LIBDIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(LIBDIR)/$(LIBFT_NAME)

SOURCES = init_function.c \
			fractol.c \
			math_functions.c \
			render_functions.c \

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -lft -l$(MLX_NAME) -lXext -lX11 -lm

$(LIBFT):
		$(MAKE) -C $(LIBDIR) all

.PHONY: clean fclean all re

clean:
		$(MAKE) -C $(LIBDIR) clean
		rm -f $(OBJ)

fclean: clean
		$(MAKE) -C $(LIBDIR) fclean
		rm -rf $(NAME)

re: fclean all
