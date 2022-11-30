/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_single_quotes_token.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:42:54 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/14 15:17:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token	*get_string_single_quotes_token(char *start, char **str)
{
	char	*next_close_quote;
	char	*tmp;
	t_token	*token;

	if (start && str && *str && *start == '\'')
	{
		next_close_quote = ft_strchr(start + 1, '\'');
		if (next_close_quote)
		{
			*str = next_close_quote + 1;
			tmp = ft_substr(start, 1, next_close_quote - start - 1);
			token = token_create(tmp, STRING_SQ_CLOSED);
			free(tmp);
			return (token);
		}
		*str = ft_strchr(*str, '\0');
		tmp = ft_strdup(start + 1);
		token = token_create(tmp, STRING_SQ_UNCLOSED);
		free(tmp);
		return (token);
	}
	return (NULL);
}
