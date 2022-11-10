/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:27:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 06:10:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token *get_next_token(char **str)
{
	char	*tmp;
	char	current_char;
	char	*next_close_quote;
	char	*str_end;

	if (!str)
		return (NULL);
	
	tmp = *str;
	
	// pular espaços em branco
	while (*tmp && *tmp == ' ')
		tmp++;
		
	if (!*tmp)
		return (NULL);
		
	current_char = *tmp;
	if (current_char == '"')
	{
		next_close_quote = ft_strchr(tmp + 1, '"');
		if (next_close_quote)
		{
			*str = next_close_quote + 1;
			return (token_create(
				ft_substr(tmp, 1, next_close_quote - tmp - 1),
				STRING_DQ_CLOSED
			));
		}
		*str = ft_strchr(*str, '\0');
		return (token_create(ft_strdup(tmp),STRING_DQ_UNCLOSED));
	}
	
	if (current_char == '\'')
	{
		next_close_quote = ft_strchr(tmp + 1, '\'');
		if (next_close_quote)
		{
			*str = next_close_quote + 1;
			return (token_create(
				ft_substr(tmp, 1, next_close_quote - tmp - 1),
				STRING_SQ_CLOSED
			));
		}
		*str = ft_strchr(*str, '\0');
		return (token_create(ft_strdup(tmp),STRING_SQ_UNCLOSED));
	}
	
	if (current_char == '<')
	{
		if (*(tmp + 1) == '<')
		{
			*str = tmp + 2;
			return (token_create(ft_strdup("<<"), INFILE_HEREDOC));
		}
		*str = tmp + 1;
		return (token_create(ft_strdup("<"), INFILE));
	}

	if (current_char == '>')
	{
		if (*(tmp + 1) == '>')
		{
			*str = tmp + 2;
			return (token_create(ft_strdup(">>"), OUTFILE_APPEND));
		}
		*str = tmp + 1;
		return (token_create(ft_strdup(">"), OUTFILE));
	}

	if (current_char == '|')
	{
		*str = tmp + 1;
		return (token_create(ft_strdup("|"), PIPE));
	}
	
	str_end = tmp;
	while (*str_end && !ft_strchr("<>|\"' ", *str_end))
		str_end++;
		
	*str = str_end;
	return (token_create(ft_substr(tmp, 0, str_end - tmp), STRING_UNQUOTED));
}