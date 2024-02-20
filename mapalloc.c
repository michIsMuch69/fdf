/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:14:57 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/20 18:21:15 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (tokens == NULL)
		return ;
	while (tokens && tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_array(int **array, int height)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < height)
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
	while (y < map->height)
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
		return (NULL);
	map->vertices = malloc(height * sizeof(int *));
	while (i < height)
	{
		map->vertices[i] = malloc(width * sizeof(int));
		if (!map->vertices[i])
			free_map(map);
		i++;
	}
	return (map);
}

int	**allocate_array(int height, int width) 
{
	int	**array;
	int	i;

	array = malloc((height + 1) * sizeof(int *));
	if (!array)
		return NULL;
	i = 0;
	while (i < height) 
	{
		array[i] = malloc(width * sizeof(int));  
		if (!array[i]) 
		{  
			while (--i >= 0) 
				free(array[i]);
			free(array);  
			return NULL;
		}
		i++;
	}
	array[height] = NULL;

	return array;
}