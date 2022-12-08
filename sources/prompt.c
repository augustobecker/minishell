/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/08 13:14:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

static char	*current_path(void);
static void	prompt_null(char *prompt);
char		*get_readline_init(void);

void	prompt(void)
{
	char	*prompt;
	char	*prompt_exp;
	char	**commands;

	prompt = get_readline_init();
	if (prompt == NULL)
		prompt_null(prompt);
	if (!syntatic_validations(prompt))
		return ;
	prompt_exp = expand_vars(prompt, g_minishell->envp);
	free(prompt);
	commands = parse_pipe(prompt_exp);
	free(prompt_exp);
	g_minishell->command_list = cmd_create_list(commands);
	array_destroy(commands);
	minishell_init_files();
	execution_process();
	clear_memory();
}

static char	*current_path(void)
{
	char	*path;

	path = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (getcwd(path, PATH_MAX) == NULL)
		return (NULL);
	else
	{
		printf(PURPLE);
		path = ft_strappend(&path, ">");
		path = ft_strappend(&path, " ");
		path = ft_strappend(&path, RESET);
		return (path);
	}
}

char	*get_readline_init(void)
{
	if (g_minishell->current_path != NULL)
		free(g_minishell->current_path);
	g_minishell->current_path = current_path();
	g_minishell->last_exit_code = 0;
	return (readline(g_minishell->current_path));
}

static void	prompt_null(char *prompt)
{
	free(prompt);
	minishell_exit(NULL);
}
