/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:16:42 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/30 09:28:40 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export(const char *var, char ***envp)
{
	char	*name;
	char	*value;
	char	**new_envp;
	char	**tmp;

	if (!var || !envp)
		return (1);
	name = get_var_name(var);
	value = get_var_value(var);
	if (name && value)
	{
		new_envp = set_env_value(name, value, *envp);
		if (new_envp)
		{
			tmp = *envp;
			*envp = new_envp;
			array_print(*envp);
			array_destroy(*envp);
		}
	}
	free(name);
	free(value);
	return (0);
}
