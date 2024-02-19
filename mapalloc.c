/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:14:57 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 15:53:00 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (tokens == NULL)
		return ;
	while (tokens && tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
void	free_map(t_map *map)
{
	int	y;
	
	y = 0;
	while (map->vertices[y])
	{
		free(map->vertices[y]);
		y++;
	}
	free(map->vertices);
	free(map);
}


