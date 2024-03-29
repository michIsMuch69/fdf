/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:13:50 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/29 18:13:45 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		i;
	size_t	fullsize;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	fullsize = i;
	return (fullsize);
}
