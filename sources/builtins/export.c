/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:16:42 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/08 14:26:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			export(char *const *vars, char ***envp);
static int	export_var(const char *var, char ***envp);

int	export(char *const *vars, char ***envp)
{
	int		return_value;
	int		args;
	int		i;
	
	if (!*vars || !envp)
		return (1);
	i = 1;
	args = array_size(vars);
	return_value = 0;
	while (i < args)
	{
		if (export_var(vars[i], envp))
			return_value = 1;
		i++;
	}
	return (return_value);
}

static int	export_var(const char *var, char ***envp)
{
	char	*name;
	char	*value;
	char	**new_envp;
	char	**tmp;

	if (var[0] == '=')
		return (printf(GREY	\
		"minishell: export: %s : not a valid identifier\n"RESET, var));
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