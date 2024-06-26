/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:02:20 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/24 13:02:23 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	clear_buffer(char *buffer, int index);
size_t	lenstr(char *s);
char	*ft_calloct(size_t nmemb, size_t size);
char	*cpy_substr(char *buffer);
char	*concate_buffer(char *buffer, char *tmp);

#endif