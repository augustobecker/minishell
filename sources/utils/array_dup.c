/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:02:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 22:57:47 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**array_dup(char *const *array)
{
	size_t	size;
	char	**new_array;

	new_array = NULL;
	size = array_size(array);
	if (array)
	{
		new_array = (char **) malloc(sizeof(char *) * (size + 1));
		if (new_array)
		{
			new_array[size] = NULL;
			while (size--)
				new_array[size] = ft_strdup(array[size]);
		}
	}
	return (new_array);
}
