/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:16:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 23:21:28 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**unset_env_value(const char *name, char *const *envp)
{
	char	*var_name;
	char	**tmp;
	size_t	i;
	size_t	cp_i;
	size_t	size;

	if (!name || !envp)
		return (NULL);
	size = array_size(envp);
	tmp = (char **) malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	cp_i = 0;
	tmp[size] = NULL;
	while (i < size)
	{
		var_name = get_var_name(envp[i]);
		if (!ft_strcmp(name, var_name))
			tmp[cp_i++] = envp[i];
		i++;
		free(var_name);
	}
	tmp[cp_i] = NULL;
	return (tmp);
}
