/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:26:02 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/20 20:58:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_a_builtin(char *command);
void	execute_builtin(t_cmd *command, char *const *envp);

t_bool	is_a_builtin(char *command)
{
	if ((ft_strcmp("echo\0", command))
		|| (ft_strcmp("cd\0", command))
		|| (ft_strcmp("pwd\0", command))
		|| (ft_strcmp("export\0", command))
		|| (ft_strcmp("unset\0", command))
		|| (ft_strcmp("env\0", command))
		|| (ft_strcmp("exit\0", command)))
		return (true);
	return (false);
}

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
		exit_code = ft_printf("env not built\n");
	else
		exit (0);
	//free memory
	exit(exit_code);
}
