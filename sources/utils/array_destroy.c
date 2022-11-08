/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:27 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 12:58:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Free memory from NULL terminated array of strings and itself.
void	array_destroy(char **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
