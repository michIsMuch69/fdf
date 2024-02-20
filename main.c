/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:59:41 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 17:42:50 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	print_array(int **array, int height, int width)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < height)
// 	{
// 		x = 0;
// 		while (x < width)
// 		{
// 			printf("%d", array[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }
t_map *initialize_map(char *file_path, int *height, int *width) 
{
    t_map *map;

    *height = calculate_map_height(file_path);
    *width = calculate_map_width(file_path);
    map = allocate_map(*height, *width);
    if (map != NULL) 
	{
        map->width = *width;
        map->height = *height;
    }
    return map;
}


void process_map(char *file_path, int height, int width) 
{
    int fd;
    int **array;

    fd = open(file_path, O_RDONLY);
    if (fd == -1) 
		return ;
    array = read_map(fd, width, height);
    printf("Width  de map  : %d\n", width);
    printf("Height de map : %d\n", height);
    printf("=====%d", array[3][3]);
    //print_array(array, height, width);
    printf("=====%d", array[3][3]);
    init_mlx_win_img(array, height, width);
    close(fd);
    free_array(array, height);
}

int main(int argc, char **argv) 
{
    t_map *map;
    int height, width;
    if (argc != 2) 
		return (-1);
    map = initialize_map(argv[1], &height, &width);
    if (map == NULL) 
	return (-1); 
    process_map(argv[1], height, width);
    free_map(map);
    return 0;
}
