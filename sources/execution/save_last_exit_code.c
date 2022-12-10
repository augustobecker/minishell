/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_last_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:57:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/07 23:25:17 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void	save_last_exit_code(int wstatus)
{
	char	**tmp_env;
	char	*num_str;

	if (WIFEXITED(wstatus))
	{
		g_minishell->last_exit_code = WEXITSTATUS(wstatus);
		tmp_env = g_minishell->envp;
		num_str = ft_itoa(g_minishell->last_exit_code);
		g_minishell->envp = set_env_value("?", num_str, tmp_env);
		array_destroy(tmp_env);
		free(num_str);
	}
}
