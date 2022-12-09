/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 14:12:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "syntax.h"

static t_bool	is_unclose_quotation(t_syntax *syntax);
static t_bool	is_invalid_pipe_position(t_syntax *syntax);
static t_bool	is_invalid_in_out(t_syntax *syntax, char **str);

t_bool	syntax_checker(char *str, char **error)
{
	t_syntax	syntax;

	syntax_init(&syntax, error);
	if (str)
		syntax.current_token = get_next_token(&str);
	if (!str || !syntax.current_token)
		return (false);
	while (syntax.current_token)
	{
		if (is_unclose_quotation(&syntax) || is_invalid_pipe_position(&syntax))
			return (false);
		if (is_invalid_in_out(&syntax, &str))
		{
			if (*(syntax.error) == NULL)
				continue ;
			return (false);
		}
		token_destroy(syntax.last_token);
		token_destroy(syntax.next_token);
		syntax.next_token = NULL;
		syntax.last_token = syntax.current_token;
		syntax.current_token = get_next_token(&str);
	}
	syntax_clear(&syntax);
	return (true);
}

static t_bool	is_unclose_quotation(t_syntax *syntax)
{
	t_tokentype	type;

	if (!syntax)
		return (false);
	type = syntax->current_token->type;
	if (type != STRING_SQ_UNCLOSED && type != STRING_DQ_UNCLOSED)
		return (false);
	*(syntax->error) = ft_strdup("Unclosed quotation marks");
	syntax_clear(syntax);
	return (true);
}

static t_bool	is_invalid_pipe_position(t_syntax *syntax)
{
	if (syntax->current_token->type != PIPE)
		return (false);
	if (is_string_token(syntax->last_token))
		return (false);
	*(syntax->error) = ft_strdup("Unexpected token: |");
	syntax_clear(syntax);
	return (true);
}

static t_bool	is_invalid_in_out(t_syntax *syntax, char **str)
{
	if (!syntax)
		return (false);
	if (!is_infile_token(syntax->current_token) && \
		!is_outfile_token(syntax->current_token))
		return (false);
	token_destroy(syntax->next_token);
	syntax->next_token = get_next_token(str);
	if (!syntax->next_token)
	{
		*(syntax->error) = ft_strdup("Unexpected token: newline");
		syntax_clear(syntax);
		return (true);
	}
	if (!is_string_token(syntax->next_token))
	{
		*(syntax->error) = ft_strjoin(
				"Unexpected token: ", syntax->next_token->value);
		syntax_clear(syntax);
		return (true);
	}
	token_destroy(syntax->last_token);
	syntax->last_token = syntax->current_token;
	syntax->current_token = syntax->next_token;
	syntax->next_token = NULL;
	return (true);
}
