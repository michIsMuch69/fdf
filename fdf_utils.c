/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:08:40 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/26 09:58:39 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_puterr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	check_lines_width(char *line, int fd, int length)
{
	if (line && (count_separator(line, ' ') != length || length == 0))
	{
		free(line);
		close(fd);
		ft_puterr("Invalid file\n");
		exit(EXIT_FAILURE);
		return (1);
	}
	return (0);
}
