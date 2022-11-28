/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:01:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/28 13:33:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO - Free memory
void	execute_builtin(t_cmd *cmd, char *const *envp)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp("echo\0", cmd->command))
		exit_code = echo(&cmd->args[1]);
	else if (ft_strcmp("pwd\0", cmd->command))
		exit_code = pwd();
	else if (ft_strcmp("export\0", cmd->command))
		exit_code = ft_printf("expor not built\n");
	else if (ft_strcmp("unset\0", cmd->command))
		exit_code = ft_printf("unset not built\n");
	else if (ft_strcmp("env\0", cmd->command))
		exit_code = env(envp);
	else
		exit (0);
	exit(exit_code);
}
