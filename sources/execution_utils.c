/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:39 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/20 14:07:14 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_not_found(char *command);
char	**get_cmd_paths(char *const *envp);

void	command_not_found(char *command)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf(GREY"minishell: %s : command not found\n"RESET, command);
	exit(COMMAND_NOT_FOUND);
}

char	**get_cmd_paths(char *const *envp)
{
	char	*paths_to_be_split;
	char	**paths;
	int		i;

	i = 0;
	paths_to_be_split = get_env_value("PATH", envp);
	if (!paths_to_be_split)
		return (NULL);
	paths = ft_split(paths_to_be_split, ':');
	while (paths[i])
	{
		paths[i] = ft_strappend(&paths[i], "/");
		i++;
	}
	free(paths_to_be_split);
	return (paths);
}
