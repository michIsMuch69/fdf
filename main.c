/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:01 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/29 17:18:29 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup(t_draw_datas *draw_datas)
{
	free(draw_datas->bounds);
	free_array(draw_datas, draw_datas->map.height);
	free_map(&draw_datas->map);
}

int	close_all(t_env *env)
{
	free_env(env);
	write(1, "Bye!\n", 5);
	exit (0);
	return (0);
}

int	file_is_valid(char *file_path)
{
	int		fd;
	int		counter;
	char	*line;
	
	//parse_file_path
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_puterr("fichier invalide"), -1);
	line = get_next_line(fd);
	if (!line)
		return (ft_puterr("error"), close(fd), -1);
	counter = 1;
	while(line)
	{
		line = get_next_line(fd);
		counter++;
	}	
	close(fd);
	return (counter - 1);
}

int	main(int argc, char **argv)
{
	t_draw_datas	draw_datas;
	t_env			*env;

	if (argc != 2)
		return (-1);
	draw_datas.map.height= file_is_valid(argv[1]);
	if (draw_datas.map.height== -1)
		return (-1);
	if(process_map(&draw_datas, argv[1]) == -1)
		return (-1); // all is free
	env = init_env(WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	calculate_projection_size(&draw_datas, env);
	draw_datas.img = init_img(env, draw_datas.bounds->max_x - \
	draw_datas.bounds->min_x + 1, draw_datas.bounds->max_y - \
	draw_datas.bounds->min_y + 1);
	render(&draw_datas, env);
	cleanup(&draw_datas);
	mlx_key_hook(env->win_ptr, key_hook, env);
	mlx_hook(env->win_ptr, 17, 1L << 0, close_all, env);
	free_image_data(env, draw_datas.img);
	mlx_loop(env->mlx_ptr);
	return (0);
}
