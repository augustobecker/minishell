/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_minihell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:02:25 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/08 13:06:10 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void		minishell_exit(char **args);
static int	set_exit_code(char *expected_exit_code);
static void	memory_clear(void);

void	minishell_exit(char **args)
{
	int	exit_code;

	exit_code = 0;
	if (array_size(args) > 1)
		exit_code = set_exit_code(args[1]);
	memory_clear();
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

static void memory_clear(void)
{
	clear_history();
	clear_memory();
	array_destroy(g_minishell->envp);
	free(g_minishell->current_path);
	g_minishell->envp = NULL;
	free(g_minishell);
}