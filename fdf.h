/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:12:47 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/26 20:11:43 by jedusser         ###   ########.fr       */
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
#define M_PI       3.14159265358979323846
#define WINDOW_HEIGHT	1920
#define WINDOW_WIDTH	1920
#define MID_WINDOW_HEIGHT 	WINDOW_HEIGHT / 2 
#define MID_WINDOW_WIDTH	WINDOW_WIDTH / 2

typedef struct s_map
{
	int	width;
	int	height;
	int	**vertices;
}		t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_data;

typedef struct s_iso
{
	int iso_x;
	int iso_y;
	int min_x;
	int max_x;
	int min_y;
	int max_y;

}	t_iso;

typedef struct s_line
{
    int x_start;
    int y_start;
    int z_start;
    int x_end;
    int y_end;
    int z_end;
	int	diff_x;
	int	diff_y;
	int	slope_x;
	int	slope_y;
	int	err;
	int	e2;
    unsigned int color;
} t_line;

int		calculate_map_width(const char *file_path);
void	free_tokens(char **tokens);
int		calculate_map_height(const char *file_path);
int		**read_map(int fd, int width, int height);
t_map	*allocate_map(int height, int width);
void	free_array(int **array, int height);
void	free_map(t_map *map);
int		**allocate_array(int height, int width);
void	init_mlx_win_img(int **array, int height, int width);
void	process_map(char *file_path, int height, int width);
void	draw_isometric_point(t_data *data, int x, int y, int z, unsigned int color);

//void	draw_line_bresenham(t_data *data, int x0, int y0, int xn, int yn, unsigned int color);
void	all_draws(t_data *img, void *mlx_ptr, int **array, int height, int width);
void draw_isometric_line(t_data *img, int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, unsigned int color);

void	draw_line_bresenham(t_data *data, t_line line);
int	get_scale(int **array);
