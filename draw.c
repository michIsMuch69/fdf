/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:42 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/23 13:40:30 by jedusser         ###   ########.fr       */
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

	start->x -= map->width / 2.0f;
	start->y -= map->height / 2.0f;
	scale = fmin((float)WINDOW_HEIGHT / (map->height + map->width), \
	(float)WINDOW_HEIGHT / (map->height + map->width));
	z_factor = sqrtf(2 / 6.f);
	iso_start->x = (scale * (start->x - start->y) * cos(M_PI / 6)) \
	+ (WINDOW_WIDTH / 2);
	iso_start->y = (scale * ((start->x + start->y) * sin(M_PI / 4) \
	- z_factor * start->z)) + (WINDOW_HEIGHT / 2);
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
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, \
	draw_datas->img->img, 0, 0);
	free_map(draw_datas->array, draw_datas->map.height);
}
