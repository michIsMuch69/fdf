/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:01 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/26 09:06:04 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_all(t_env *env)
{
	free_env(env);
	write(1, "Bye!\n", 5);
	exit (0);
	return (0);
}

int	valid_file_extension(char *file_path)
{
	size_t	i;

	i = ft_strlen(file_path);
	if (i <= 4 || file_path[i - 5] == '/')
		return (1);
	i -= 1;
	if (file_path[i] != 'f')
		return (1);
	if (file_path[i - 1] != 'd')
		return (1);
	if (file_path[i - 2] != 'f')
		return (1);
	if (file_path[i - 3] != '.')
		return (1);
	return (0);
}

int	file_is_valid(char *file_path, t_draw_datas *draw_datas)
{
	int		fd;
	int		counter;
	char	*line;
	int		length;

	if (valid_file_extension(file_path))
		return (ft_puterr("Invalid file extension\n"), -1);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_puterr("Invalid file\n"), -1);
	line = get_next_line(fd);
	if (!line)
		return (ft_puterr("Map is empty\n"), close(fd), -1);
	length = count_separator(line, ' ');
	counter = 1;
	while (line)
	{
		free (line);
		line = get_next_line(fd);
		check_lines_width(line, fd, length);
		counter++;
	}
	close(fd);
	draw_datas->map.width = length;
	return (counter - 1);
}

int	check_data(t_draw_datas *draw_datas)
{
	int	i;

	i = 0;
	while (i < draw_datas->map.height)
	{
		if (draw_datas->array[i] == NULL)
			return (free_array(draw_datas, draw_datas->map.height), -1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_draw_datas	draw_datas;
	t_env			*env;

	if (argc != 2)
		return (-1);
	draw_datas.map.height = file_is_valid(argv[1], &draw_datas);
	if (draw_datas.map.height == -1)
		return (-1);
	if (process_map(&draw_datas, argv[1]) == -1)
		return (-1);
	if (check_data(&draw_datas) == -1)
		return (-1);
	env = init_env(WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!env)
		return (free_array(&draw_datas, draw_datas.map.height), -1);
	draw_datas.img = init_img(env);
	if (!draw_datas.img)
		return (free_env(env), \
				free_array(&draw_datas, draw_datas.map.height), -1);
	render(&draw_datas, env);
	mlx_key_hook(env->win_ptr, key_hook, env);
	mlx_hook(env->win_ptr, 17, 1L << 0, close_all, env);
	free_image_data(env, draw_datas.img);
	mlx_loop(env->mlx_ptr);
	return (0);
}
