/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:40:43 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/26 08:53:09 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_separator(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_lenstr(const char *s, char c, int start)
{
	size_t	count;

	count = 0;
	while (s[start] != c && s[start])
	{
		count++;
		start++;
	}
	return (count);
}

static void	ft_free_array(char **array, size_t index)
{
	while (index > 0)
	{
		free(array[index]);
		index--;
	}
	free(array[0]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	x;
	char	**dst;

	dst = ft_calloc(sizeof(char *), (count_separator(s, c) + 1));
	if (!dst)
		return (NULL);
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			dst[x++] = ft_substr(s, i, ft_lenstr(s, c, i));
			if (!dst[x - 1])
			{
				ft_free_array(dst, x - 1);
				return (NULL);
			}
			i = i + ft_lenstr(s, c, i);
		}
		else
			i++;
	}
	return (dst);
}
