# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jean-micheldusserre <jean-micheldusserr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 11:46:43 by jedusser          #+#    #+#              #
#    Updated: 2024/04/19 13:01:18 by jean-michel      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = bresenham.c draw.c fdf_utils.c free.c hooks.c init.c main.c points.c map.c
GNL_SRC = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c


OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o) $(GNL_SRC:%.c=%.o) 

CC = gcc
CFLAGS = -g3 -Wextra -Wall -Werror -Ilibft -Iminilibx-linux 


all: mlx  libft $(NAME)

mlx:
	make -C ./minilibx-linux

libft:
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re mlx libft