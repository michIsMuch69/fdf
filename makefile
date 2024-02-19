# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 09:10:55 by jedusser          #+#    #+#              #
#    Updated: 2024/02/19 14:10:05 by jedusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = $(wildcard *.c)
GNL_SRC = $(wildcard get_next_line/*.c)
LIBFT_SRC = $(wildcard libft/*.c) 
FT_PRINTF_SRC = $(wildcard ft_printf/*.c)
#MLX_SRC = $(wildcard minilibx-linux/*.c)

OBJ = $(SRC:.c=.o) $(GNL_SRC:.c=.o) $(FT_PRINTF_SRC:.c=.o) #$(MLX_SRC:.c=.o)

CC = gcc
CFLAGS = -g3 -Werror -Wextra -Wall -Iincludes -Ilibft -Iminilibx-linux -Ift_printf

.PHONY: all clean fclean re mlx ft_printf libft

all: mlx ft_printf libft $(NAME)

mlx:
	make -C ./minilibx-linux

ft_printf:
	make -C ./ft_printf 

libft:
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -Lft_printf -lftprintf -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C ./minilibx-linux
	make clean -C ./ft_printf
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./ft_printf
	make fclean -C ./libft

re: fclean all

