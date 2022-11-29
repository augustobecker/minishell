/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:01:12 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 22:52:25 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

// TODO - Free memory
void	execute_builtin(t_cmd *cmd)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp("echo", cmd->command))
		exit_code = echo(&cmd->args[1]);
	else if (ft_strcmp("pwd", cmd->command))
		exit_code = pwd();
	else if (ft_strcmp("export", cmd->command))
		exit_code = printf("export not built\n");
	else if (ft_strcmp("unset", cmd->command))
		exit_code = printf("unset not built\n");
	else if (ft_strcmp("env", cmd->command))
		exit_code = env(g_data.env);
	else
		exit (0);
	exit(exit_code);
}
