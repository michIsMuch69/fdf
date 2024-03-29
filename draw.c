/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:42 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/29 17:07:11 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + x * \
		(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	get_iso_coord(t_start *start, t_iso_start *iso_start, t_map *map)
{
	float	scale;
	float	z_factor;

	if (map->height < 50 && map->width < 50)
		scale = 30.0;
	else if (map->height <= 100 && map->width <= 100)
		scale = 8.0;
	else if (map->height <= 200 && map->width <= 200)
		scale = 5.0;
	else if (map->height <= 300 && map->width <= 300)
		scale = 1.5;
	else if (map->height > 300 && map->width > 300)
		scale = 0.5;
	else
		scale = 40;
	z_factor = 3.5;
	iso_start->x = scale * (start->x - start->y) * cos(M_PI / 6);
	iso_start->y = scale * (start->x + start->y) * sin(M_PI / 4) \
	- z_factor * start->z;
}

void	process_row(t_draw_datas *draw_datas, int y)
{
	int	x;

	x = 0;
	while (x < draw_datas->map.width)
	{
		process_point(draw_datas, x, y);
		x++;
	}
}

void	draw_grid(t_draw_datas *draw_datas)
{
	int	y;

	y = 0;
	while (y < draw_datas->map.height)
	{
		process_row(draw_datas, y);
		y++;
	}
}

void	render(t_draw_datas *draw_datas, t_env *env)
{
	draw_grid(draw_datas);
	center_image_in_window(env, draw_datas->img);
}
