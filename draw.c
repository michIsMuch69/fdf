/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:38 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/22 16:50:32 by jedusser         ###   ########.fr       */
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

void draw_line_bresenham(t_data *data, int x0, int y0, int xn, int yn, unsigned int color) {
    int dx, dy, sx, sy, err, e2;

    // Calculate dx, dy
    if (xn > x0) 
	{
        dx = xn - x0;
        sx = 1;
    } 
	else 
	{
        dx = x0 - xn;
        sx = -1;
    }

    if (yn > y0) 
	{
        dy = yn - y0;
        sy = 1;
    } 
	else 
	{
        dy = y0 - yn;
        sy = -1;
    }
    err = dx - dy;
    while (1)
	{
        my_mlx_pixel_put(data, x0, y0, color); // Set pixel at (x0, y0)
        if (x0 == xn && y0 == yn) 
			break;
        e2 = 2 * err;
        if (e2 > -dy) 
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) 
		{
            err += dx;
            y0 += sy;
        }
    }
}

void draw_isometric_line(t_data *data, int x0, int y0, int z0, int xn, int yn, int zn, unsigned int color) {
    int iso_x0, iso_y0, iso_xn, iso_yn;

	int scale;

	scale = 20;
    // Calculate isometric coordinates for start point
    iso_x0 = scale * ((x0 - y0) * cos(M_PI / 6)) + data->width / 8;
    iso_y0 = scale * ((x0 + y0) * sin(M_PI / 6) - z0) + data->height / 2;

    // Calculate isometric coordinates for end point
    iso_xn = scale * ((xn - yn) * cos(M_PI / 6)) + data->width / 8;
    iso_yn = scale * ((xn + yn) * sin(M_PI / 6) - zn) + data->height / 2;

    // Draw line between isometric points
    draw_line_bresenham(data, iso_x0, iso_y0, iso_xn, iso_yn, color);
}
