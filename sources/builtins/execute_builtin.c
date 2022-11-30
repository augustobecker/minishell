/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:01:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/30 22:43:42 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int	execute_builtin(t_cmd *cmd)
{
	if (ft_strcmp("echo", cmd->command))
		return (echo(&cmd->args[1]));
	if (ft_strcmp("cd", cmd->command))
		return (cd(cmd->args, array_size(cmd->args)));
	if (ft_strcmp("pwd", cmd->command))
		return (pwd());
	if (ft_strcmp("export", cmd->command))
		return (export(cmd->args[1], &g_data.env));
	if (ft_strcmp("unset", cmd->command))
		return (unset(cmd->args[1], &g_data.env));
	if (ft_strcmp("env", cmd->command))
		return (env(g_data.env));
	return (g_data.last_exit_code);
}