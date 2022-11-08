/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:53:25 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 12:57:50 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Return the number os elements on NULL terminated array of strings.
size_t	array_size(char *const *array)
{
	size_t	size;

	size = 0;
	while (array && *array)
	{
		size++;
		array++;
	}
	return (size);
}
