// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   projinfo.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/11 12:57:58 by jedusser          #+#    #+#             */
// /*   Updated: 2024/04/11 09:23:43 by jedusser         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

 #include "fdf.h"

// void	update_bounds(t_iso_start *iso_start, t_bounds *bounds)
// {
// 	if (iso_start->x < bounds->min_x)
// 		bounds->min_x = iso_start->x;
// 	if (iso_start->x > bounds->max_x)
// 		bounds->max_x = iso_start->x;
// 	if (iso_start->y < bounds->min_y)
// 		bounds->min_y = iso_start->y;
// 	if (iso_start->y > bounds->max_y)
// 		bounds->max_y = iso_start->y;
// }

// void	update_bounds_with_iso_coords(t_draw_datas *draw_datas)
// {
// 	t_iso_start	iso_start;
// 	t_start		start;
// 	int			x;
// 	int			y;

// 	y = 0;
// 	while (y < draw_datas->map.height)
// 	{
// 		x = 0;
// 		while (x < draw_datas->map.width)
// 		{
// 			start.x = x;
// 			start.y = y;
// 			start.z = draw_datas->array[y][x];
// 			get_iso_coord(&start, &iso_start, &draw_datas->map);
// 			update_bounds(&iso_start, draw_datas->bounds);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	calculate_projection_size(t_draw_datas *draw_datas, t_env *env)
// {
// 	int	width;
// 	int	height;

// 	init_bounds(draw_datas);
// 	update_bounds_with_iso_coords(draw_datas);
// 	width = draw_datas->bounds->max_x - draw_datas->bounds->min_x + 1;
// 	height = draw_datas->bounds->max_y - draw_datas->bounds->min_y + 1;
// 	draw_datas->img = init_img(env, width, height);
// 	if (!draw_datas->img)
// 	{
// 		perror("Error initializing image");
// 		return ;
// 	}
// 	free_image_data(env, draw_datas->img);
// }

void	center_image_in_window(t_env *env, t_data *img)
{
	// int	offset_x;
	// int	offset_y;

	// offset_x = (WINDOW_WIDTH - img->width) / 2;
	// offset_y = (WINDOW_HEIGHT - img->height) / 2;
	// mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, 
	// img->img, offset_x, offset_y);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, \
	img->img, 0, 0);
}
