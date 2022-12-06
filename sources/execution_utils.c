/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:39 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/06 12:53:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

char	**get_cmd_paths(void)
{
	char	*paths_to_be_split;
	char	**paths;
	int		i;

	i = 0;
	paths_to_be_split = get_env_value("PATH", g_data.env);
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
