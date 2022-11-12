/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:28:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 18:11:40 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	array_append(char ***array, char *value)
{
	size_t	size;
	char	**new_array;

	if (!array)
		return ;
	size = array_size(*array) + 1;
	new_array = (char **) malloc(sizeof(char *) * (size + 1));
	if (new_array)
	{
		new_array[size] = NULL;
		new_array[--size] = value;
		while (size--)
			new_array[size] = *(*array + size);
		free(*array);
	}
	*array = new_array;
}
