/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 18:15:03 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//initalisation des variables graphiques et checks preliminaires

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 4);
	*(unsigned int*)dst = color;
}

void init_mlx_win_img(int **array, int height, int width) 
{
    void *mlx_ptr;
    void *win_ptr;
    t_data img;
    int x; 
	int	y;
    int a;
	int b;
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return;
    win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "FDF");
    img.img = mlx_new_image(mlx_ptr, 1920, 1080); // Adjusted to match window size
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    y = 0;
    b = 50; // offset vertical
    while (y < height) 
	{
        x = 0;
        a = 50; //  offset horizontal
        while (x  < width) 
		{
            if (array[y][x] > 0) 
                my_mlx_pixel_put(&img, a, b, 0x00FF0000); 
			else 
                my_mlx_pixel_put(&img, a, b, 0xFFFFFF); 
            x++;
            a += 50; 
        }
        y++;
        b += 50; // Adjust step as needed
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
    mlx_loop(mlx_ptr);
}
	//s'assurer que l'icremantatin de a et b ne depasse pas les limites de l'image