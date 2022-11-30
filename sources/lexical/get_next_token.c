/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/14 17:25:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

static void	skip_spaces(char **str);

t_token	*get_next_token(char **str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	skip_spaces(str);
	tmp = *str;
	if (*tmp == '"')
		return (get_string_double_quotes_token(tmp, str));
	if (*tmp == '\'')
		return (get_string_single_quotes_token(tmp, str));
	if (*tmp == '<')
		return (get_infile_token(tmp, str));
	if (*tmp == '>')
		return (get_outfile_token(tmp, str));
	if (*tmp == '|')
	{
		*str = tmp + 1;
		return (token_create("|", PIPE));
	}
	return (get_string_unquoted_token(tmp, str));
}

static void	skip_spaces(char **str)
{
	if (!str || !*str)
		return ;
	while (*(*str) && *(*str) == ' ')
		(*str)++;
}
