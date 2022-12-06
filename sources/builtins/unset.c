/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:26:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/06 18:16:32 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset(const char *name, char ***envp)
{
	char	**new_envp;
	char	**tmp;

	if (name && envp)
	{
		new_envp = unset_env_value(name, *envp);
		if (new_envp)
		{
			tmp = *envp;
			*envp = new_envp;
			array_destroy(tmp);
		}
	}
	return (0);
}
