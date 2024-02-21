/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:42:38 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/21 16:30:25 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//formules et fonctions pour dessiner ce que je veux

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

//void render()
void	draw_isometric_point(t_data *data, int x, int y, int z, unsigned int color) 
{
    int	iso_x;
    int	iso_y;
	int scale;
	
	scale = 20; // echelle de l'image projetee
	iso_x = scale * ((x - y) * cos(M_PI / 6));
	iso_y = scale * ((x + y) * sin(M_PI / 6) - z);
	
    //pour centrer la carte
    iso_x += data->width / 8 ;  
    iso_y += data->height / 2; 

    my_mlx_pixel_put(data, iso_x, iso_y, color);
}
