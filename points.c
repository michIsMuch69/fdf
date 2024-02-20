/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:55:26 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 18:21:08 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_line(char *line, int **array, int y, int width) 
{
    char	**line_vertices;
    int		x = 0;
    int		vertice;

    line_vertices = ft_split(line, ' ');
    while (line_vertices[x] != NULL && x < width) 
	{
        vertice = ft_atoi(line_vertices[x]);
        array[y][x] = vertice;
        x++;
    }
    free_tokens(line_vertices);
}

int	**read_map(int fd, int width, int height) 
{
    int y;
    int **array;
    char *line;
	
	line = get_next_line(fd);
    array = allocate_array(height, width);
	y = 0;
    while (line != NULL && y < height) 
	{
        process_line(line, array, y, width);
        free(line);
        y++;
		line = get_next_line(fd);
    }
    close(fd);
    return array;
}

