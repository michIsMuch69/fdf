/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:57 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx_win_img(int **array, int height, int width)
{
	t_data	*img;
	void	*mlx_ptr;
	void	*win_ptr;

	img = malloc(sizeof (t_data));
	if (!img)
		return ;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return ;
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	all_draws(img, mlx_ptr, array, height, width);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
	mlx_loop(mlx_ptr);
}