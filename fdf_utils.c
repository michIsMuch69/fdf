/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:08:40 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 15:08:57 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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