/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:51:59 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/29 18:30:35 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	process_line(char *line, t_draw_datas *draw_datas, int i)
{
	char	**line_vertices;
	int		x;
	int		vertice;

	x = 0;
	draw_datas->array[i] = malloc (draw_datas->map.width * sizeof(int));
	if (!(draw_datas->array[i]))
		return(free_array(draw_datas, draw_datas->map.height), -1);
	line_vertices = ft_split(line, ' ');
	if (!line_vertices)
		return (-1);
	while (line_vertices[x] != NULL) // WARNING
	{
		vertice = ft_atoi(line_vertices[x]);
		if(vertice > 1000)
		{
			vertice = vertice * 0.5;
		}
		draw_datas->array[i][x] = vertice;
		x++;
	}
	free_tokens(line_vertices);
	return (0);
}

int	get_array(t_draw_datas *draw_datas, int fd, char *tmp, int i)
{
	tmp = get_next_line(fd);
	if (!tmp)
		return (-1); 
	draw_datas->map.width =(int)countwords(tmp, ' ');
	if (draw_datas->map.width == 0)
			return(free_array(draw_datas, draw_datas->map.height), -1);
	printf("count = %d\n", draw_datas->map.width);
	process_line(tmp, draw_datas, i);
	free(tmp);	
	i++;
	while(tmp || i < draw_datas->map.height)
	{
		tmp = get_next_line(fd);
		printf("count = %zu\n", countwords(tmp, ' '));
		if (!tmp)
			return (-1);
		process_line(tmp, draw_datas, i);
		if((int)countwords(tmp, ' ') != draw_datas->map.width && (int)countwords(tmp, ' ') != 0)
		{
			ft_puterr("Invalid map");
			free_array(draw_datas, draw_datas->map.height);
			return (-1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int	process_map(t_draw_datas *draw_datas, char *file_path)
{
	char	*tmp;
	int 	fd;
	int		i;

	tmp = NULL;
	fd = open(file_path, O_RDONLY);
	draw_datas->array = malloc(draw_datas->map.height * sizeof(int *));
	if (fd == -1 || !draw_datas->array)
		return (-1);
	i = 0;
	int x = 0;
	if(get_array(draw_datas, fd, tmp, i)== -1)
		return (-1);
	while (i < draw_datas->map.height)
	{
		while (x < draw_datas->map.width)
		{
			printf("%d ",draw_datas->array[i][x]);
			x++;
		}
		printf("\n");
		i++;
	}
	close(fd);
	return (0);
}
