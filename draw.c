/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:38 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/27 10:09:22 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//formules et fonctions pour dessiner ce que je veux
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;
	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

void draw_line_bresenham(t_data *img, t_line line) 
{
	if (line.x_end > line.x_start)
	{
		line.diff_x = line.x_end - line.x_start;
		line.slope_x = 1;
	} 
	else 
	{
		line.diff_x = line.x_start - line.x_end;
		line.slope_x = -1;
	}
	if (line.y_end > line.y_start) 
	{
		line.diff_y = line.y_end - line.y_start;
		line.slope_y = 1;
	} 
	else 
	{
		line.diff_y = line.y_start - line.y_end;
		line.slope_y = -1;
	}
	line.err = line.diff_x - line.diff_y;
	while (1)
	{
		my_mlx_pixel_put(img, line.x_start, line.y_start, line.color); 
		if (line.x_start == line.x_end && line.y_start == line.y_end) 
			break;
		line.e2 = 2 * line.err;
		if (line.e2 >= -line.diff_y) 
		{
			line.err -= line.diff_y;
			line.x_start += line.slope_x;
		}
		if (line.e2 <= line.diff_x) 
		{
			if (line.y_start == line.y_end)
				break;
			line.err += line.diff_x;
			line.y_start += line.slope_y;
		}
	}
}



void draw_isometric_line(t_data *img, int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, unsigned int color)
{
	int		iso_x_start;
	int		iso_y_start;
	int		iso_x_end;
	int		iso_y_end;
	float	z_factor;
	int		scale;
	t_line	line;

	scale = 15;
	// scale = WINDOW_HEIGHT / map->height;

	z_factor = 0.5;
	iso_x_start = scale * ((x_start - y_start) * cos(M_PI / 6)) + MID_WINDOW_WIDTH;
	iso_y_start = scale * ((x_start + y_start) * sin(M_PI / 4) - z_factor * z_start) + img->height / 3;
	iso_x_end = scale * ((x_end - y_end) * cos(M_PI / 6)) + MID_WINDOW_WIDTH;
	iso_y_end = scale * ((x_end + y_end) * sin(M_PI / 4) - z_factor * z_end) + img->height / 3;
	line.x_start = iso_x_start;
	line.y_start = iso_y_start;
	line.x_end = iso_x_end;
	line.y_end = iso_y_end;
	line.color = color;
	draw_line_bresenham(img, line);
}



void	all_draws(t_data *img, void *mlx_ptr, int **array, int height, int width)
{
	int	x;
	int	y;

	img->img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->height = WINDOW_HEIGHT;
	img->width = WINDOW_WIDTH;
	y = 0;
	while (y < height - 1) 
	{
		x = 0;
		while (x < width - 1) 
		{
			draw_isometric_line(img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFF0000);//white
			// trace sur l'axe x
			draw_isometric_line(img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFF0000);//red
			// trac sur l'axe y
			x++;
		}
		//derniere colonne de chaque rangege
		draw_isometric_line(img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFF0000);//blue
		//axe y de front/
		y++;
	}
	// derniere rangee
	x = 0;
	while (x < width - 1)
	{
		draw_isometric_line(img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFF0000);//green
		//axe x de front.
		x++;
	}
}