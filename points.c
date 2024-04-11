/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:08:33 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/11 10:47:59 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_points(t_draw_datas *draw_datas, int x, int y, t_iso_start *iso_s)
{
	t_start		start;

	start.x = x;
	start.y = y;
	start.z = draw_datas->array[y][x];
	get_iso_coord(&start, iso_s, &draw_datas->map);
}

void	process_point(t_draw_datas *draw_datas, int x, int y)
{
	t_start		end;
	t_iso_start	iso_start;
	t_iso_start	iso_end;

	init_points(draw_datas, x, y, &iso_start);
	if (x + 1 < draw_datas->map.width)
	{
		end.x = x + 1;
		end.y = y;
		end.z = draw_datas->array[y][x + 1];
		get_iso_coord(&end, &iso_end, &draw_datas->map);
		bresenham(draw_datas->img, iso_start, iso_end, 0xFFFFFF);
	}
	if (y + 1 < draw_datas->map.height)
	{
		end.x = x;
		end.y = y + 1;
		end.z = draw_datas->array[y + 1][x];
		get_iso_coord(&end, &iso_end, &draw_datas->map);
		bresenham(draw_datas->img, iso_start, iso_end, 0xFFFFFF);
	}
}
