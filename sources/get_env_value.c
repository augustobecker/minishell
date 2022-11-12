/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:00:29 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 07:41:06 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_value(const char *name, char *const *envp)
{
	char	*var_name;

	while (name && envp && *envp)
	{
		var_name = get_var_name(*envp);
		if (var_name && ft_strcmp(var_name, name))
			return (get_var_value(*envp));
		envp++;
	}
	return (NULL);
}
