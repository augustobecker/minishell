/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:14:55 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/30 09:15:07 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_env_value(char *name, char *value, char *const *envp)
{
	char	*var_name;
	char	*var_str;
	char	**tmp;

	if (!name || !value)
		return (array_dup(envp));
	var_name = ft_strjoin(name, "=");
	if (!var_name)
		return (array_dup(envp));
	var_str = ft_strjoin(var_name, value);
	if (!var_str)
	{
		free(var_name);
		return (array_dup(envp));
	}
	free(var_name);
	tmp = unset_env_value(name, envp);
	array_append(&tmp, var_str);
	return (tmp);
}
