/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:16:42 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 19:10:50 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			export(char *const *args, char ***envp);
static int	set_export(const char *var, char ***envp);

int	export(char *const *args, char ***envp)
{
	int	return_value;
	int	size;
	int	i;

	i = 1;
	size = array_size(args);
	if (size == 1)
		return (1);
	return_value = 0;
	while (i < size)
	{
		if (args[i][0] == '\0' || args[i][0] == '=')
		{
			printf(GREY \
			"minishell: export: `%s': not a valid identifier\n" \
			RESET, args[i]);
			return_value = 1;
		}
		else
			set_export(args[i], &(*envp));
		i++;
	}
	return (return_value);
}

static int	set_export(const char *var, char ***envp)
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
			array_destroy(tmp);
		}
	}
	free(name);
	free(value);
	return (0);
}
