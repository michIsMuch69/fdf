/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:49:55 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/29 17:07:49 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "fdf.h"

typedef struct s_line		t_line;
typedef struct s_env		t_env;
typedef struct s_map		t_map;
typedef struct s_data		t_data;
typedef struct s_start		t_start;
typedef struct s_end		t_end;
typedef struct s_iso_start	t_iso_start;
typedef struct s_iso_end	t_iso_end;
typedef struct s_diff		t_diff;
typedef struct s_slope		t_slope;
typedef struct s_scale		t_scale;
typedef struct s_err		t_err;
typedef struct s_bounds		t_bounds;
typedef struct s_draw_datas	t_draw_datas;
typedef struct s_bresenham	t_bresenham;

struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
};

struct	s_map
{
	int	width;
	int	height;
	int	**vertices;
};
struct s_draw_datas
{
	t_bounds	*bounds;
	t_data		*img;
	t_map		map;
	int			**array;
};
struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
};


struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	float	scale;
};

struct s_start
{
	int	x;
	int	y;
	int	z;
};

struct	s_iso_start
{
	int	x;
	int	y;
};

struct s_bounds
{
	int	max_y;
	int	max_x;	
	int	min_y;	
	int	min_x;	
};

struct	s_iso_end
{
	int	x;
	int	y;
};

#endif