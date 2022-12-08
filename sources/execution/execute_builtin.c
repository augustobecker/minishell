/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:01:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/08 14:25:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

int	execute_builtin(t_cmd *cmd)
{
	if (ft_strcmp("echo", cmd->command))
		return (echo(&cmd->args[1]));
	if (ft_strcmp("cd", cmd->command))
		return (cd(cmd->args, array_size(cmd->args)));
	if (ft_strcmp("pwd", cmd->command))
		return (pwd());
	if (ft_strcmp("export", cmd->command))
		return (export(cmd->args, &g_minishell->envp));
	if (ft_strcmp("unset", cmd->command))
		return (unset(cmd->args[1], &g_minishell->envp));
	if (ft_strcmp("env", cmd->command))
		return (env(g_minishell->envp));
	return (g_minishell->last_exit_code);
}
