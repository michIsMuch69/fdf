/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:39:15 by jedusser          #+#    #+#             */
/*   Updated: 2024/02/19 15:12:08 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(gnl_ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	gnl_ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > gnl_ft_strlen(s))
		return (malloc(1));
	if (len > gnl_ft_strlen(s + start))
		len = gnl_ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*str;
	size_t	length;

	length = gnl_ft_strlen(s1);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = length + gnl_ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str[i] = s2[i - length];
		i++;
	}
	str[i] = '\0';
	return (str);
}
