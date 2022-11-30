/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:19:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/30 13:48:33 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	array_print(char *const *array)
{
	while (array && *array)
	{
		printf("%s\n", *array);
		array++;
	}
}
