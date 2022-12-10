/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:14:49 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/09 19:48:40 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void		minishell_exit(const char *exit_code);
static int	set_exit_code(const char *exit_code);

void	minishell_exit(const char *exit_code)
{
	int		exit_code_value;

	exit_code_value = set_exit_code(exit_code);
	clear_history();
	clear_memory();
	array_destroy(g_minishell->envp);
	free(g_minishell->current_path);
	g_minishell->envp = NULL;
	free(g_minishell);
	exit (exit_code_value);
}

static int	set_exit_code(const char *exit_code)
{
	int	i;

	i = 0;
	if (!exit_code)
		return (0);
	if (exit_code[0] == '-')
		i++;
	while (exit_code[i])
	{
		if (!ft_isdigit(exit_code[i]))
			return (0);
		i++;
	}
	return (ft_atoi(exit_code));
}
