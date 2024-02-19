/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:14:57 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 14:50:39 by jedusser         ###   ########.fr       */
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
void free_map(t_map *map)
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
int	calculate_map_width(const char *file_path)
{
	int		fd;
	char	*line;
	char	**tokens;
	int		width;

	width = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close (fd);
		return (0);
	}
	tokens = ft_split(line, ' ');
	while (tokens && tokens[width] != NULL)
		width++;
	free_tokens(tokens);
	free(line);
	close (fd);
	return (width);
}

int	calculate_map_height(const char *file_path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
	
