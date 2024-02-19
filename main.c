/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:59:41 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 17:37:27 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
void print_array(int **array, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			printf("%d", array[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
		
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		**array;
	char	*file_path;
	int		fd;
	int		height;
	int		width;

	if (argc != 2)
		return (-1);
	file_path = argv[1];
	height = calculate_map_height(file_path);
	width = calculate_map_width(file_path);
	map = allocate_map(height, width);
	map->width = width;
	map->height = height;
	fd = open(file_path, O_RDONLY);
	array = read_map(fd, width, height);
	printf("Width  de map  : %d\n", map->width);
	printf("Height de map : %d\n", map->height);
	print_array(array, height, width);
	free_array(array);
	free_map(map);
		
}