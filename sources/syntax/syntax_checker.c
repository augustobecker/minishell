/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 21:06:02 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "syntax.h"

static t_bool	is_unclosed_quotation(t_syntax *syntax);
static t_bool	is_invalid_pipe(t_syntax *syntax);
static t_bool	is_invalid_in_out(t_syntax *syntax);
static void		move_syntax(t_syntax *syntax, char **str);

t_bool	syntax_checker(char *str, char **error)
{
	t_syntax	syntax;

	syntax_init(&syntax, error);
	if (str)
		syntax.next_token = get_next_token(&str);
	if (!str || !syntax.next_token)
		return (false);
	move_syntax(&syntax, &str);
	while (syntax.current_token)
	{
		if (is_unclosed_quotation(&syntax))
			return (false);
		if (is_invalid_pipe(&syntax))
			return (false);
		if (is_invalid_in_out(&syntax) && *(syntax.error))
			return (false);
		move_syntax(&syntax, &str);
	}
	syntax_clear(&syntax);
	return (true);
}

static t_bool	is_unclosed_quotation(t_syntax *syntax)
{
	t_tokentype	type;

	if (!syntax || !syntax->current_token)
		return (false);
	type = syntax->current_token->type;
	if (type != STRING_SQ_UNCLOSED && type != STRING_DQ_UNCLOSED)
		return (false);
	*(syntax->error) = ft_strdup("Unclosed quotation marks");
	syntax_clear(syntax);
	return (true);
}

static t_bool	is_invalid_pipe(t_syntax *syntax)
{
	if (syntax->current_token->type != PIPE)
		return (false);
	if (is_string_token(syntax->last_token) && syntax->next_token)
		return (false);
	if (is_string_token(syntax->last_token) && !syntax->next_token)
		*(syntax->error) = ft_strdup("Unexpected token: newline");
	else
		*(syntax->error) = ft_strdup("Unexpected token: |");
	syntax_clear(syntax);
	return (true);
}

static t_bool	is_invalid_in_out(t_syntax *syntax)
{
	if (!syntax)
		return (false);
	if (!is_infile_token(syntax->current_token) && \
		!is_outfile_token(syntax->current_token))
		return (false);
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
	return (true);
}

static void	move_syntax(t_syntax *syntax, char **str)
{
	if (!syntax)
		return ;
	token_destroy(syntax->last_token);
	syntax->last_token = syntax->current_token;
	syntax->current_token = syntax->next_token;
	syntax->next_token = get_next_token(str);
}
