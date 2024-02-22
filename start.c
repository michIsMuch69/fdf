/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/22 22:31:44 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//initalisation des variables graphiques et checks preliminaires
// void render_map(int	**array, int height, int width)
// {
	
// }
// void init_mlx_win_img(int **array, int height, int width) 
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     t_data img;
//     int x; 
// 	int	y;
    
//     mlx_ptr = mlx_init();
//     if (!mlx_ptr)
//         return;
//     win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
//     img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); // Adjusted to match window size
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	img.height = WINDOW_HEIGHT;
// 	img.width = WINDOW_WIDTH;
//     y = 0;
//     while (y < height) 
// 	{
//         x = 0;
//         while (x < width) 
// 		{
// 			if (array[y][x] > 0)
//                 draw_isometric_point(&img, x, y, array[y][x], 0xFFFFFF);
// 			else
//                 draw_isometric_point(&img, x, y, array[y][x], 0xFF0000); 
				
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 50, 50);
//     mlx_loop(mlx_ptr);
// }
	//s'assurer que l'icremantatin de a et b ne depasse pas les limites de l'image

    void init_mlx_win_img(int **array, int height, int width) 
{
    void *mlx_ptr;
    void *win_ptr;
    t_data img;
    int x; 
    int y;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return;
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
    img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.height = WINDOW_HEIGHT;
    img.width = WINDOW_WIDTH;
    y = 0;
    while (y < height - 1) // Adjust to prevent accessing out-of-bounds
    {
        x = 0;
        while (x < width - 1) // Adjust to prevent accessing out-of-bounds
        {
            	// tout simplement, ajoute un instruction tres simple pour afficher le slignes sur x et sur y 

            // ligne vers la droite

            draw_isometric_line(&img, x, y, array[y][x], x + 1, y, array[y][x + 1], 0xFFFFFF);
            // ligne descendante
            draw_isometric_line(&img, x, y, array[y][x], x, y + 1, array[y + 1][x], 0xFFFFFF);

            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
    mlx_loop(mlx_ptr);
}

A noter : que se passe t'il lorsque deux espaces/ ou un signe - ? ? incremanter la taille de un par signe ????