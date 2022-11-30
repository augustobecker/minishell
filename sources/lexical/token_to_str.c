/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 08:05:55 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 08:49:41 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*str_add_prefix(const char *prefix, const char *str);
static char		*str_add_postfix(const char *postfix, const char *str);
static char		*str_add_prefix_postfix(const char *value, const char *str);

char	*token_to_str(t_token *token)
{	
	if (!token)
		return (NULL);
	if (token->type == STRING_UNQUOTED)
		return (ft_strdup(token->value));
	if (token->type == STRING_DQ_UNCLOSED)
		return (str_add_prefix("\"", token->value));
	if (token->type == STRING_SQ_UNCLOSED)
		return (str_add_prefix("'", token->value));
	if (token->type == STRING_DQ_CLOSED)
		return (str_add_prefix_postfix("\"", token->value));
	if (token->type == STRING_SQ_CLOSED)
		return (str_add_prefix_postfix("'", token->value));
	if (token->type == INFILE)
		return (ft_strdup("<"));
	if (token->type == INFILE_HEREDOC)
		return (ft_strdup("<<"));
	if (token->type == OUTFILE)
		return (ft_strdup(">"));
	if (token->type == OUTFILE_APPEND)
		return (ft_strdup(">>"));
	if (token->type == PIPE)
		return (ft_strdup("|"));
}

static char	*str_add_prefix(const char *prefix, const char *str)
{
	return (ft_strjoin(prefix, str));
}

static char	*str_add_postfix(const char *postfix, const char *str)
{
	return (ft_strjoin(str, postfix));
}

static char	*str_add_prefix_postfix(const char *value, const char *str)
{
	char	*tmp;
	char	*result;

	tmp = str_add_prefix(value, str);
	result = str_add_postfix(value, tmp);
	free(tmp);
	return (result);
}
