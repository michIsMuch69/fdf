# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 11:46:43 by jedusser          #+#    #+#              #
#    Updated: 2024/03/27 11:56:44 by jedusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = bresenham.c draw.c fdf_utils.c free.c hooks.c init.c main.c mapalloc.c points.c projinfo.c map.c
GNL_SRC = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c


OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o) $(GNL_SRC:%.c=%.o) 

CC = gcc
CFLAGS = -g3 -Wextra -Wall -Werror -Ilibft -Iminilibx-linux -Ift_printf


all: mlx ft_printf libft $(NAME)

mlx:
	make -C ./minilibx-linux

ft_printf:
	make -C ./ft_printf

libft:
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./minilibx-linux
	make clean -C ./ft_printf
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./ft_printf
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re mlx ft_printf libft