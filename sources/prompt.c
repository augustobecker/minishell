/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/30 22:50:44 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"

extern t_data g_data;

void		prompt(t_data *data);
static char	*current_path(void);
static void	prompt_null(char *prompt, char *path);

void	prompt(t_data *data)
{
	char	*prompt;
	char	*prompt_exp;
	char	**commands;
	t_list	*list;

	g_data.prompt_path = current_path();
	g_data.last_exit_code = 0;
	prompt = readline(g_data.prompt_path);
	if (prompt == NULL)
		prompt_null(prompt, g_data.prompt_path);
	if (!syntatic_validations(prompt))
		return;
	prompt_exp = expand_vars(prompt, data->env);
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

static void prompt_null(char *prompt, char *path)
{
	if (prompt == NULL)
	{
		free(path);
		free(prompt);
		exit(0);
	}
}
