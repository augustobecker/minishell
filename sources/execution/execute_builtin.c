/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:01:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 23:33:04 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

int			execute_builtin(t_cmd *cmd);
static void	set_exit_code(int exit_code);

int	execute_builtin(t_cmd *cmd)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp("echo", cmd->command))
		exit_code = echo(&cmd->args[1]);
	else if (ft_strcmp("cd", cmd->command))
		exit_code = cd(cmd->args, array_size(cmd->args));
	else if (ft_strcmp("pwd", cmd->command))
		exit_code = pwd();
	else if (ft_strcmp("export", cmd->command))
		exit_code = export(cmd->args, &g_minishell->envp);
	else if (ft_strcmp("unset", cmd->command))
		exit_code = unset(cmd->args[1], &g_minishell->envp);
	else if (ft_strcmp("env", cmd->command))
		exit_code = env(g_minishell->envp);
	set_exit_code(exit_code);
	return (exit_code);
}

static void	set_exit_code(int exit_code)
{
	char	**tmp_env;
	char	*num_str;

	g_minishell->last_exit_code = exit_code;
	tmp_env = g_minishell->envp;
	num_str = ft_itoa(g_minishell->last_exit_code);
	g_minishell->envp = set_env_value("?", num_str, tmp_env);
	array_destroy(tmp_env);
	free(num_str);
}
