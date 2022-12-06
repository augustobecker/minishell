/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/06 12:42:41 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static char	*current_path(void);
static void	prompt_null(char *prompt, char *path);

void	prompt(void)
{
	char	*prompt;
	char	*prompt_exp;
	char	**commands;
	t_list	*list;

	if (g_data.prompt_path != NULL)
		free(g_data.prompt_path);
	g_data.prompt_path = current_path();
	g_data.last_exit_code = 0;
	prompt = readline(g_data.prompt_path);
	if (prompt == NULL)
		prompt_null(prompt, g_data.prompt_path);
	if (!syntatic_validations(prompt))
		return ;
	prompt_exp = expand_vars(prompt, g_data.env);
	free(prompt);
	commands = parse_pipe(prompt_exp);
	free(prompt_exp);
	list = cmd_create_list(commands);
	array_destroy(commands);
	init_global_struct();
	init_files(list);
	execution_process(list);
	clear_memory(list);
}

static char	*current_path(void)
{
	char	*path;

	path = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (getcwd(path, PATH_MAX) == NULL)
		return (NULL);
	else
	{
		ft_printf(PURPLE);
		path = ft_strappend(&path, ">");
		path = ft_strappend(&path, " ");
		path = ft_strappend(&path, RESET);
		return (path);
	}
}

static void	prompt_null(char *prompt, char *path)
{
	if (!prompt)
		return ;
	free(path);
	free(prompt);
	exit(0);
}
