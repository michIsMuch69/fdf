/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:12:47 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 14:24:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_map
{
	int	width;
	int	height;
	int	**vertices;
}		t_map;

int		calculate_map_width(const char *file_path);
void	free_tokens(char **tokens);
int		calculate_map_height(const char *file_path);
int		**read_map(int fd, int width, int height);
t_map	*allocate_map(int height, int width);
void	free_array(int **array, int height);
void	free_map(t_map *map);
int		**vert_array(int height, int width);
void 	init_mlx_win_img();


