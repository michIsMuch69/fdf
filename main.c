/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:59:41 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 15:54:55 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

t_map	*allocate_map(int height, int width)
{
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return(NULL);
	map->vertices = malloc(height * sizeof(int *));
	while(i < height)
	{
		map->vertices[i] = malloc(width * sizeof(int));
		if (!map->vertices[i])
		{
			while (i >= 0)
			{
				free(map->vertices[i]);
				i--;
			}
			free(map);
			free(map->vertices);
			return (NULL);
		}
		i++;
	}
	return (map);
}
int	main(int argc, char **argv)
{
	t_map	*map;
	char	*file_path;
	//int		fd;
	int		height;
	int		width;

	if (argc != 2)
		return (-1);
	file_path = argv[1];
	height = calculate_map_height(file_path);
	width = calculate_map_width(file_path);
	map = allocate_map(height, width);
	
	//fd = open(file_path, O_RDONLY);
	printf("Width  de map  : %d\n", map->width);
	printf("Height de map : %d\n", height);

	
}