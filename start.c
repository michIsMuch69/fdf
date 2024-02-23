/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/23 07:34:50 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	init_mlx_win_img(int **array, int height, int width) 
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     t_data img;
//     int x; 
//     int y;

//     mlx_ptr = mlx_init();
//     if (!mlx_ptr)
//         return;
//     win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
//     img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//     img.height = WINDOW_HEIGHT;
//     img.width = WINDOW_WIDTH;
//     y = 0;
//     while (y < height - 1) // Adjust to prevent accessing out-of-bounds
//     {
//         x = 0;
//         while (x < width - 1) // Adjust to prevent accessing out-of-bounds
//         {
//             	// tout simplement, ajoute un instruction tres simple pour afficher le slignes sur x et sur y 

//             // ligne vers la droite
//             draw_isometric_line(&img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFFFFFF);
//             // ligne descendante
//             draw_isometric_line(&img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFFFFFF);

//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
//     mlx_loop(mlx_ptr);
// }

//A noter : que se passe t'il lorsque deux espaces/ ou un signe - ? ? incremanter la taille de un par signe ????

void init_mlx_win_img(int **array, int height, int width) 
{
	t_data *img;
    void *mlx_ptr;
    void *win_ptr;
	img = malloc(sizeof (t_data));
	if (!img)
		return ;
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return;
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
    all_draws(img, mlx_ptr, array, height, width);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img->img, 0, 0);
    mlx_loop(mlx_ptr);
}

void	all_draws(t_data *img, void *mlx_ptr, int **array, int height, int width)
{
	int	x;
	int	y;

	img->img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->height = WINDOW_HEIGHT;
    img->width = WINDOW_WIDTH;
    y = 0;
    while (y < height - 1) 
    {
        x = 0;
        while (x < width - 1) 
        {
            draw_isometric_line(img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFFFFFF);
            draw_isometric_line(img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFFFFFF);
            x++;
        }
        //derniere colonne de chaque rangege
        draw_isometric_line(img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFFFFFF);
        y++;
    }
    // derniere rangee
    x = 0;
    while (x < width - 1)
    {
        draw_isometric_line(img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFFFFFF);
        x++;
    }
}