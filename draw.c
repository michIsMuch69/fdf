/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:38 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/26 15:13:28 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//formules et fonctions pour dessiner ce que je veux


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}


void draw_line_bresenham(t_data *data, t_line line) 
{
    int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

    if (line.x_end > line.x_start)
	{
        dx = line.x_end - line.x_start;
        sx = 1;
    } 
	else 
	{
        dx = line.x_start - line.x_end;
        sx = -1;
    }
    if (line.y_end > line.y_start) 
	{
        dy = line.y_end - line.y_start;
        sy = 1;
    } 
	else 
	{
        dy = line.y_start - line.y_end;
        sy = -1;
    }
    err = dx - dy;
    while (1)
	{
        my_mlx_pixel_put(data, line.x_start, line.y_start, line.color); 
        if (line.x_start == line.x_end && line.y_start == line.y_end) 
			break;
        e2 = 2 * err;
        if (e2 >= -dy) 
		{
            err -= dy;
            line.x_start += sx;
        }
        if (e2 <= dx) 
		{
			if (line.y_start == line.y_end)
				break;
            err += dx;
            line.y_start += sy;
        }
    }
}
void draw_isometric_line(t_data *data, int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, unsigned int color)
{
    int		iso_x_start;
    int		iso_y_start;
    int		iso_x_end;
    int		iso_y_end;
    float	z_factor;
    int		scale;

    scale = 20;
    z_factor = 0.2;
    iso_x_start = scale * ((x_start - y_start) * cos(M_PI / 6)) + data->width / 4;
    iso_y_start = scale * ((x_start + y_start) * sin(M_PI / 4) - z_factor * z_start) + data->height / 4;
    iso_x_end = scale * ((x_end - y_end) * cos(M_PI / 6)) + data->width / 4;
    iso_y_end = scale * ((x_end + y_end) * sin(M_PI / 4) - z_factor * z_end) + data->height / 4;

    t_line line;
    line.x_start = iso_x_start;
    line.y_start = iso_y_start;
    line.x_end = iso_x_end;
    line.y_end = iso_y_end;
    line.color = color;

    draw_line_bresenham(data, line);
}

