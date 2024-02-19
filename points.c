/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:55:26 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 17:24:48 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**vert_array(int height, int width)
{
	int	**array;
	int	i;

	i = 0;
	array = malloc(height * sizeof(int *));
	while (i < height)
	{
		array[i] = malloc(width * sizeof(int));
		i++;
	}
	return (array);
}

// int **fill_array(int **array, int y, int x, int vertice)
// {
// 	array = vert_array(width, height);
// 	array[y][x] = vertice;
// }

int **read_map(int fd, int width, int height)
{
	int		x;
	int		y;
	int		vertice;
	int		**array;
	char	*line;
	char 	**line_vertices;
	
	//line = NULL;
	array = vert_array(height, width);
	y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		line_vertices = ft_split(line, ' ');
		if(line_vertices == NULL)
			break;
		x = 0;
		while (line_vertices[x] != NULL)
		{
			vertice = ft_atoi(line_vertices[x]);
			array[y][x] = vertice;
			//map->vertices[y] = vertice;
			x++;
		}
		y++;
	}
	close (fd);
	return (array);
}
