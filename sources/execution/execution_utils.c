/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:39 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 23:25:23 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

char	**get_cmd_paths(void)
{
	char	*paths_to_be_split;
	char	**paths;
	int		i;

	i = 0;
	paths_to_be_split = get_env_value("PATH", g_minishell->envp);
	if (!paths_to_be_split)
		return (NULL);
	paths = ft_split(paths_to_be_split, ':');
	while (paths[i])
	{
		paths[i] = ft_strappend(&paths[i], "/");
		i++;
	}
	free (paths_to_be_split);
	return (paths);
}
