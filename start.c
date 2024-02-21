/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/21 12:01:47 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//initalisation des variables graphiques et checks preliminaires

void init_mlx_win_img(int **array, int height, int width) 
{
    void *mlx_ptr;
    void *win_ptr;
    t_data img;
    int x; 
	int	y;
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return;
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
    img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT); // Adjusted to match window size
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.height = WINDOW_HEIGHT;
	img.width = WINDOW_WIDTH;
    y = 0;
    while (y < height) 
	{
        x = 0;
        while (x < width) 
		{
                draw_isometric_point(&img, x, y, array[y][x], 0xFFFFFF); 
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 50, 50);
    mlx_loop(mlx_ptr);
}
	//s'assurer que l'icremantatin de a et b ne depasse pas les limites de l'image