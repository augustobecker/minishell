/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:00:29 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/03 14:31:15 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	array_size(char *const *array);
static void		destroy_array(char **array);

char	*get_env_value(const char *name, char *const *envp)
{
	char	**name_value;
	char	*tmp;

	if (!name || !envp)
		return (NULL);
	while (*envp)
	{
		name_value = ft_split(*envp, '=');
		if (!name_value || array_size(name_value) != 2)
		{
			destroy_array(name_value);
			return (NULL);
		}
		if (ft_strncmp(name, name_value[0], ft_strlen(name) + 1) == 0)
		{
			tmp = ft_strdup(name_value[1]);
			destroy_array(name_value);
			return (tmp);
		}
		destroy_array(name_value);
		envp++;
	}
	return (NULL);
}

static size_t	array_size(char *const *array)
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

static void	destroy_array(char **array)
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
