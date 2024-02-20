/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:55:26 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 17:08:21 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	**allocate_array(int height, int width)
// {
// 	int	**array;
// 	int	i;

// 	i = 0;
// 	array = malloc(height + 1 * sizeof(int *));
// 	if(!array)
// 		return NULL;
// 	while (i < height)
// 	{
// 		array[i] = malloc(width * sizeof(int));
// 		i++;
// 	}
// 	return (array);
// }

int	**allocate_array(int height, int width) 
{
	int	**array;
	int	i;

	array = malloc((height + 1) * sizeof(int *));  // Allocate space for height + 1 pointers
	if (!array)
		return NULL;
	i = 0;
	while (i < height) 
	{
		array[i] = malloc(width * sizeof(int));  // Allocate each row
		if (!array[i]) 
		{  // Handle allocation failure
			while (--i >= 0) 
				free(array[i]);
			free(array);  // Free the array itself
			return NULL;
		}
		i++;
	}
	array[height] = NULL;  // Null-terminate the array

	return array;
}



int	**read_map(int fd, int width, int height)
{
	int		x;
	int		y;
	int		vertice;
	int		**array;
	char	*line;
	char	**line_vertices;

	array = allocate_array(height, width);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_vertices = ft_split(line, ' ');
		if (line_vertices == NULL)
			break ;
		x = 0;
		while (line_vertices[x] != NULL )
		{
			if (x >= width)
				break ;
			vertice = ft_atoi(line_vertices[x]);
			array[y][x] = vertice;
			x++;
		}
		free(line);
		free_tokens(line_vertices);
		line = get_next_line(fd);
		y++;
		if (y >= height)
			break ;
	}
	close (fd);
	return (array);
}
