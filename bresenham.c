/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:53 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/26 12:33:12 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_steps(int *sx, int *sy, t_iso_start start, t_iso_start end)
{
	if (start.x < end.x)
		*sx = 1;
	else
		*sx = -1;
	if (start.y < end.y)
		*sy = 1;
	else
		*sy = -1;
}

void	bresenham(t_data *img, t_iso_start start, t_iso_start end, int color)
{
	t_bresenham	bresenham;

	bresenham.dx = abs(end.x - start.x);
	bresenham.dy = -abs(end.y - start.y);
	calculate_steps(&bresenham.sx, &bresenham.sy, start, end);
	bresenham.err = bresenham.dx + bresenham.dy;
	while (1)
	{
		my_mlx_pixel_put(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		bresenham.e2 = 2 * bresenham.err;
		if (bresenham.e2 >= bresenham.dy)
		{
			bresenham.err += bresenham.dy;
			start.x += bresenham.sx;
		}
		if (bresenham.e2 <= bresenham.dx)
		{
			bresenham.err += bresenham.dx;
			start.y += bresenham.sy;
		}
	}
}
