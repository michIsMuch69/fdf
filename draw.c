/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:38 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/22 22:29:36 by jedusser         ###   ########.fr       */
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

// //void render()
// void	draw_isometric_point(t_data *data, int x, int y, int z, unsigned int color) 
// {
//     int	iso_x;
//     int	iso_y;
// 	int scale;
	
// 	scale = 20; // echelle de l'image projetee
// 	iso_x = scale * ((x - y) * cos(M_PI / 6));
// 	iso_y = scale * ((x + y) * sin(M_PI / 6) - z);
	
//     //pour centrer la carte
//     iso_x += data->width / 8 ;  
//     iso_y += data->height / 2; 

//     my_mlx_pixel_put(data, iso_x, iso_y, color);
// }

void draw_line_bresenham(t_data *data, int x_start, int y_start, int x_end, int y_end, unsigned int color) {
    int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

    // Calculate dx, dy
    if (x_end > x_start) 
	{
        dx = x_end - x_start;
        sx = 1;
    } 
	else 
	{
        dx = x_start - x_end;
        sx = -1;
    }

    if (y_end > y_start) 
	{
        dy = y_end - y_start;
        sy = 1;
    } 
	else 
	{
        dy = y_start - y_end;
        sy = -1;
    }
    err = dx - dy;
    while (1)
	{
        my_mlx_pixel_put(data, x_start, y_start, color); // Set pixel at (x_start, y_start)
        if (x_start == x_end && y_start == y_end) 
			break;
        e2 = 2 * err;
        if (e2 >= -dy) 
		{
            err -= dy;
            x_start += sx;
        }
        if (e2 <= dx) 
		{
			if (y_start == y_end)
				break;
            err += dx;
            y_start += sy;
        }
    }
}

void draw_isometric_line(t_data *data, int x_start, int y_start, int z_start, int x_end, int y_end, int z_end, unsigned int color) {
    int iso_x_start;
	int iso_y_start;
	int iso_x_end;
	int iso_y_end;
	float z_factor;
	int scale;

	scale = 20;
	z_factor = 0.2;
    // Calculate isometric coordinates for start point
    iso_x_start = scale * ((x_start - y_start) * cos(M_PI / 6)) + data->width / 4;
    iso_y_start = scale * ((x_start + y_start) * sin(M_PI / 4) - z_factor * z_start) + data->height / 4;
    // Calculate isometric coordinates for end point
    iso_x_end = scale * ((x_end - y_end) * cos(M_PI / 6)) + data->width / 4;
    iso_y_end = scale * ((x_end + y_end) * sin(M_PI / 4) - z_factor * z_end) + data->height / 4;

    // Draw line between isometric points
    draw_line_bresenham(data, iso_x_start, iso_y_start, iso_x_end, iso_y_end, color);
}
