/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:25 by jedusser          #+#    #+#             */
/*   Updated: 2024/03/26 14:06:24 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		free_env(env);
		write(1, "Bye!\n", 5);
		exit(0);
	}
	return (0);
}
