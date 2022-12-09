/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 11:29:15 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool is_quotation_unclosed(t_token *token);
static void	destroy_tokens(t_token **last, t_token **current, t_token **next);

t_bool	syntax_checker(char *str, char **error)
{
	t_token	*last_token;
	t_token *current_token;
	t_token *next_token;;

	*error = NULL;
	next_token = NULL;
	last_token = NULL;
	
	if (str)
		current_token = get_next_token(&str);
	if (!str || !current_token)
		return (false);

	while (current_token)
	{
		if (is_quotation_unclosed(current_token))
		{
			*error = ft_strdup("Unclosed quotation marks");
			destroy_tokens(&last_token, &current_token, &next_token);
			return (false);
		}

		if (current_token->type == PIPE && !is_string_token(last_token))
		{
			*error = ft_strdup("Unexpected token: |");
			destroy_tokens(&last_token, &current_token, &next_token);
			return (false);
		}
		if (is_infile_token(current_token) || is_outfile_token(current_token))
		{
			token_destroy(next_token);
			next_token = get_next_token(&str);
			if (!next_token)
			{
				*error = ft_strdup("Unexpected token: newline");
				destroy_tokens(&last_token, &current_token, &next_token);
				return (false);
			}
			if (!is_string_token(next_token))
			{
				*error = ft_strjoin("Unexpected token: ", next_token->value);
				destroy_tokens(&last_token, &current_token, &next_token);
				return (false);
			}
			token_destroy(last_token);
			last_token = current_token;
			current_token = next_token;
			next_token = NULL;
			continue ;
		}
		token_destroy(last_token);
		token_destroy(next_token);
		next_token = NULL;
		last_token = current_token;
		current_token = get_next_token(&str);
	}
	destroy_tokens(&last_token, &current_token, &next_token);
	return (true);
}

static t_bool is_quotation_unclosed(t_token *token)
{
	if (token->type == STRING_DQ_UNCLOSED)
		return (true);
	if (token->type == STRING_SQ_UNCLOSED)
		return (true);
	return (false);
}

static void	destroy_tokens(t_token **last, t_token **current, t_token **next)
{
	token_destroy(*last);
	token_destroy(*current);
	token_destroy(*next);
	*last = NULL;
	*current = NULL;
	*next = NULL;
}