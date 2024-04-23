/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:57:34 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/23 15:29:05 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_image_data(t_env *env, t_data *img)
{
	if (!img)
		return ;
	if (img->img)
	{
		mlx_destroy_image(env->mlx_ptr, img->img);
	}
	free(img);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (tokens == NULL)
		return ;
	while (tokens && tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_array(t_draw_datas *draw_datas, int height)
{
	int	i;

	i = -1;
	if (draw_datas->array == NULL)
		return ;
	while (++i < height)
		if (draw_datas->array[i])
			free(draw_datas->array[i]);
	free(draw_datas->array);
}

void	free_map(int **vertices, int size)
{
	int	y;

	y = 0;
	if (vertices == NULL)
		return ;
	while (y < size)
	{
		free(vertices[y]);
		y++;
	}
	free(vertices);
}

void	free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->win_ptr)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
		free(env);
	}
}
