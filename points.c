/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:55:26 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 18:12:09 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	**allocate_array(int height, int width) 
{
	int	**array;
	int	i;

	array = malloc((height + 1) * sizeof(int *));
	if (!array)
		return NULL;
	i = 0;
	while (i < height) 
	{
		array[i] = malloc(width * sizeof(int));  
		if (!array[i]) 
		{  
			while (--i >= 0) 
				free(array[i]);
			free(array);  
			return NULL;
		}
		i++;
	}
	array[height] = NULL;

	return array;
}

void process_line(char *line, int **array, int y, int width) 
{
    char **line_vertices;
    int x = 0;
    int vertice;

    line_vertices = ft_split(line, ' ');
    while (line_vertices[x] != NULL && x < width) 
	{
        vertice = ft_atoi(line_vertices[x]);
        array[y][x] = vertice;
        x++;
    }
    free_tokens(line_vertices);
}

int **read_map(int fd, int width, int height) 
{
    int y = 0;
    int **array;
    char *line;

    array = allocate_array(height, width);
    while ((line = get_next_line(fd)) != NULL && y < height) 
	{
        process_line(line, array, y, width);
        free(line);
        y++;
    }
    close(fd);
    return array;
}

