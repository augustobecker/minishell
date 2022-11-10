/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_double_quotes_token.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:42:04 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 06:51:09 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token	*get_string_double_quotes_token(char *start, char **str)
{
	char	*next_close_quote;

	if (start && str && *str && *start == '"')
	{
		next_close_quote = ft_strchr(start + 1, '"');
		if (next_close_quote)
		{
			*str = next_close_quote + 1;
			return (token_create(
					ft_substr(start, 1, next_close_quote - start - 1),
					STRING_DQ_CLOSED
				));
		}
		*str = ft_strchr(*str, '\0');
		return (token_create(ft_strdup(start), STRING_DQ_UNCLOSED));
	}
	return (NULL);
}
