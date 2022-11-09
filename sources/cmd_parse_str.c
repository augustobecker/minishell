/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:20:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/08 21:55:17 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*get_next_token(char **str);
static int			has_token(char *str);
static t_bool 		is_infile_token(const char *token);
static t_bool 		is_outfile_token(const char *token);
static void			skip_spaces(char **str);
static char 		*get_infile_outfile(char **prompt, t_cmd *cmd);

t_cmd	*cmd_parse_str(const char *str)
{
	t_cmd		*cmd;
	char		*token;
	char		*prompt;
	char		*prompt_cpy;

	if (!str || !*str)
		return (NULL);
	cmd = cmd_create("", NULL, NULL, NULL);
	prompt = ft_strtrim(str, " ");
	prompt_cpy = prompt;
	if (cmd && prompt)
	{
		token = get_infile_outfile(&prompt, cmd);
		cmd->command = token;
		if (has_token(prompt))
		{
			size_t	args_size = 0;
			char	*tmp;
			while (*prompt && *prompt != '<' && *prompt   != '>')
			{
				prompt++;
				args_size++;
			}
			if (args_size > 0)
			{
				tmp = ft_substr(prompt - args_size, 0, args_size);
				cmd->args = ft_split(tmp, ' ');
				free(tmp);
			}
		}
		free(get_infile_outfile(&prompt, cmd));
	}
	free(prompt_cpy);
	return (cmd);
}

static char *get_infile_outfile(char **prompt, t_cmd *cmd)
{
	char	*token;

	token = get_next_token(prompt);
	while (is_infile_token(token) || is_outfile_token(token))
	{
		if (is_infile_token(token))
		{
			file_destroy(&cmd->infile);
			cmd->infile = file_create(get_next_token(prompt), 0, COMMON_FILE) ;
			if (ft_strcmp("<<", token) && cmd->infile)
				cmd->infile->type = HEREDOC_FILE;
			// free(token);
			// token = get_next_token(prompt);
		}
		if (is_outfile_token(token))
		{
			file_destroy(&cmd->outfile);
			cmd->outfile = file_create(get_next_token(prompt), 0, COMMON_FILE) ;
			if (ft_strcmp(">>", token) && cmd->outfile)
				cmd->outfile->type = APPEND_FILE;
			// free(token);
			// token = get_next_token(prompt);
		}
		free(token);
		token = get_next_token(prompt);
	}
	return (token);
}

static void	skip_spaces(char **str)
{
	if (!str || !*str)
		return ;
	while(*(*str) && *(*str) == ' ')
		(*str)++;
}

// Return the next sequence of chars different from space character.
static char	*get_next_token(char **str)
{
	size_t	token_end_at;
	const char	*tmp_str;

	if (!str || !*str)
		return (NULL);
	token_end_at = 0;
	tmp_str = *str;
	skip_spaces(str);
	while (*(*str) && *(*str)!= ' ')
	{
		token_end_at++;
		(*str)++;
	}
	skip_spaces(str);
	return (ft_substr(tmp_str, 0, token_end_at));
}

// Check if has in the string any character different from space.
static int	has_token(char *str)
{
	while (str && *str)
	{
		if (*str != ' ')
			return (true);
		str++;
	}
	return (false);
}

static t_bool is_infile_token(const char *token)
{
	if (token && ft_strncmp("<", token, ft_strlen(token) + 1) == 0)
		return (true);
	if (token && ft_strncmp("<<", token, ft_strlen(token) + 1) == 0)
		return (true);
	return (false);
}

static t_bool is_outfile_token(const char *token)
{
	if (token && ft_strncmp(">", token, ft_strlen(token) + 1) == 0)
		return (true);
	if (token && ft_strncmp(">>", token, ft_strlen(token) + 1) == 0)
		return (true);
	return (false);
}
