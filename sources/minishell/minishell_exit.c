/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:46:30 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/08 22:15:02 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;


void		minishell_exit(char **args);
static int	set_exit_code(char *expected_exit_code);
static void	memory_clear_2(void);

void	minishell_exit(char **args)
{
	int	exit_code;

	exit_code = 0;
	if (array_size(args) > 1)
		exit_code = set_exit_code(args[1]);
	memory_clear_2();
	exit (exit_code);
}

static int set_exit_code(char *exit_code)
{
	int	i;

	i = 0;
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

static void memory_clear_2(void)
{
	//clear_history();
	clear_memory();
	array_destroy(g_minishell->envp);
	free(g_minishell->current_path);
	g_minishell->envp = NULL;
	free(g_minishell);
}
