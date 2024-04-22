/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:59 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/22 15:31:32 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int process_line(char *line, t_draw_datas *draw_datas, int i)
{
    char **line_vertices;
    int x = 0;
    int vertice;

    draw_datas->array[i] = ft_calloc((size_t) draw_datas->map.width, sizeof(int));
    if (!draw_datas->array[i])
    	return (-1);
    line_vertices = ft_split(line, ' '); // ca leak
    if (!line_vertices)
        return (-1); 
    while (x < draw_datas->map.width)
	{
        vertice = ft_atoi(line_vertices[x]);
        draw_datas->array[i][x] = vertice;
        x++;
    }
    free_tokens(line_vertices);
    return 0;
}


int	get_array(t_draw_datas *draw_datas, int fd, int i)
{
	char	*tmp;
	
	tmp = NULL;
	tmp = get_next_line(fd); //ca leak plus
	if (!tmp)
		return (-1);
	draw_datas->map.width = (int)countwords(tmp, ' ');
	if (draw_datas->map.width == 0)
		return (free(tmp), -1);
	if (process_line(tmp, draw_datas, i) == -1)
		return (free(tmp), -1);
	free(tmp);
	i++;
	while (i <= draw_datas->map.height)
	{
		tmp = NULL;
		tmp = get_next_line(fd); //leak et segfault
		if (!tmp)
			break ;
		if (process_line(tmp, draw_datas, i) == -1)
			return (free(tmp), -1);
		free(tmp);
		i++;
	}
	return (0);
}

int	process_map(t_draw_datas *draw_datas, char *file_path)
{
	int		fd;
	int		i;

	draw_datas->array = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	draw_datas->array = ft_calloc(draw_datas->map.height, sizeof(int *));
	if (!draw_datas->array)
		return (close(fd), -1);
	i = 0;
	if (get_array(draw_datas, fd, i) == -1)
		return (free_array(draw_datas, draw_datas->map.height), close(fd), -1);
	close(fd);
	return (0);
}
