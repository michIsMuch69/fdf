/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:39:17 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/23 14:18:47 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "structures.h"
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

/*/////////////////////////////////////////////
			FDF HEADER FILEs
/////////////////////////////////////////////*/

# define M_PI       3.14159265358979323846
# define WINDOW_HEIGHT	1720
# define WINDOW_WIDTH	1720
# define INT_MAX	2147483647
# define INT_MIN -2147483648

/*=============================bresenham.c===============================*/

void		bresenham(t_data *img, t_iso_start start, \
t_iso_start end, int color);

/*===============================draw.c==================================*/

void		my_mlx_pixel_put(t_data *img, int x, int y, int color);
void		get_iso_coord(t_start *start, t_iso_start *iso_start, t_map *map);
void		draw_grid(t_draw_datas *draw_datas);
void		render(t_draw_datas *draw_datas, t_env *env);

/*=============================fdf_utils.c===============================*/

void		ft_putstr(char *str);
void		ft_puterr(char *str);

/*===============================free.c==================================*/

void		free_tokens(char **tokens);
void		free_env(t_env *env);
void		free_image_data(t_env *env, t_data *img);
void		free_array(t_draw_datas *draw_datas, int height);
void		free_map(int **vertices, int size);
/*===============================hooks.c=================================*/

int			key_hook(int keycode, t_env *env);

/*===============================init.c==================================*/

t_map		*initialize_map(char *file_path, int *height, int *width);
t_env		*init_env(int width, int height, char *title);
t_data		*init_img(t_env *env);
void		init_bounds(t_draw_datas *draw_datas);

/*===============================map.c===================================*/

int			**read_map(int fd, t_draw_datas *draw_datas);
int			process_map(t_draw_datas *draw_datas, char *file_path);

/*==============================points.c=================================*/

void		process_point(t_draw_datas *draw_datas, int x, int y);

/*=============================projinfo.c=================================*/

void		calculate_projection_size(t_draw_datas *draw_datas, t_env *env);
void		center_image_in_window(t_env *env, t_data *img);

#endif