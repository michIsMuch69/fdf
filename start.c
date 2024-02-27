/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/27 14:35:26 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	key_hook(int keycode, t_env *env)
{
	static int *scale;
	
	if(!scale)
		scale = get_scale(NULL);
	if(keycode == 65307)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit (0);
	}
	if (keycode == 111)
		*scale += 1;
	return (0);
}



void	init_mlx_win_img(int **array, int height, int width)
{
	t_data	*img;
	t_env	env;

	img = malloc(sizeof(t_data));
	if (!img)
		return ;
	env.mlx_ptr = mlx_init();
	if (!env.mlx_ptr)
		return ;
	env.win_ptr = mlx_new_window(env.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	all_draws(img, env.mlx_ptr, array, height, width);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, img->img, -130, 0);
	mlx_key_hook(env.win_ptr, key_hook, &env);
	
	mlx_loop(env.mlx_ptr);
}