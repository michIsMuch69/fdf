/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:14:57 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 17:49:40 by jedusser         ###   ########.fr       */
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

void	free_array(int **array)
{
	int	i;

	i = 0;
	if(array == NULL)
		return ;
	while (array && array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
void	free_map(t_map *map)
{
	int	y;
	
	y = 0;
	if (map == NULL)
		return ;
	while (map->vertices[y])
	{
		free(map->vertices[y]);
		y++;
	}
	free(map->vertices);
	free(map);
}

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
