/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:14 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/22 10:31:14 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_img(t_env *env)
{
	t_data	*img;

	img = NULL;
	img = malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->img = mlx_new_image(env->mlx_ptr, img->width, img->height);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	return (img);
}

t_env	*init_env(int width, int height, char *title)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
	{
		free(env);
		return (NULL);
	}
	env->win_ptr = mlx_new_window(env->mlx_ptr, width, height, title);
	if (!env->win_ptr)
	{
		free(env->mlx_ptr);
		free(env);
		return (NULL);
	}
	return (env);
}

