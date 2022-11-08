/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:00:29 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 13:15:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			array_destroy(name_value);
			return (NULL);
		}
		if (ft_strncmp(name, name_value[0], ft_strlen(name) + 1) == 0)
		{
			tmp = ft_strdup(name_value[1]);
			array_destroy(name_value);
			return (tmp);
		}
		array_destroy(name_value);
		envp++;
	}
	return (NULL);
}
