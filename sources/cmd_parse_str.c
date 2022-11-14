/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:20:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/14 21:27:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	set_string(t_cmd *cmd, t_token **current, char **prompt);
static t_bool	set_in_out(t_cmd *cmd, t_token **c, t_token **n, char **prompt);
static void		set_outfile(t_cmd *cmd, t_token *current, t_token *next);
static void		set_infile(t_cmd *cmd, t_token *current, t_token *next);

t_cmd	*cmd_parse_str(const char *str)
{
	t_token	*current;
	t_token	*next;
	t_cmd	*cmd;
	char	*prompt;

	if (!str)
		return (NULL);
	prompt = (char *) str;
	current = get_next_token(&prompt);
	if (!current)
		return (NULL);
	cmd = cmd_create("", NULL, NULL, NULL);
	while (current && current->type != PIPE)
	{
		if (set_string(cmd, &current, &prompt) || \
			set_in_out(cmd, &current, &next, &prompt))
			continue ;
		token_destroy(current);
		current = next;
	}
	token_destroy(current);
	return (cmd);
}

static t_bool	set_string(t_cmd *cmd, t_token **current, char **prompt)
{
	if (is_string_token(*current))
	{
		if (ft_strcmp("", cmd->command))
		{
			free(cmd->command);
			cmd->command = ft_strdup((*current)->value);
		}
		array_append(&cmd->args, ft_strdup((*current)->value));
		token_destroy(*current);
		*current = get_next_token(prompt);
		return (true);
	}
	return (false);
}

static t_bool	set_in_out(t_cmd *cmd, t_token **c, t_token **n, char **prompt)
{
	*n = get_next_token(prompt);
	if (is_infile_token(*c) && is_string_token(*n))
	{
		set_infile(cmd, *c, *n);
		token_destroy(*c);
		token_destroy(*n);
		*c = get_next_token(prompt);
		return (true);
	}
	if (is_outfile_token(*c) && is_string_token(*n))
	{
		set_outfile(cmd, *c, *n);
		token_destroy(*c);
		token_destroy(*n);
		*c = get_next_token(prompt);
		return (true);
	}
	return (false);
}

static void	set_outfile(t_cmd *cmd, t_token *current, t_token *next)
{
	file_destroy(&cmd->outfile);
	cmd->outfile = file_create(next->value, 0, COMMON_FILE);
	if (cmd->outfile && current->type == OUTFILE_APPEND)
		cmd->outfile->type = APPEND_FILE;
}

static void	set_infile(t_cmd *cmd, t_token *current, t_token *next)
{
	file_destroy(&cmd->infile);
	cmd->infile = file_create(next->value, 0, COMMON_FILE);
	if (cmd->infile && current->type == INFILE_HEREDOC)
		cmd->infile->type = HEREDOC_FILE;
}
