/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_unquoted_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:43:36 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/14 15:19:30 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token	*get_string_unquoted_token(char *start, char **str)
{
	char	*str_end;
	char	*tmp;
	t_token	*token;

	if (!start || !str || !*start || !*str)
		return (NULL);
	str_end = start;
	while (*str_end && !ft_strchr("<>|\"' ", *str_end))
		str_end++;
	*str = str_end;
	tmp = ft_substr(start, 0, str_end - start);
	token = token_create(tmp, STRING_UNQUOTED);
	free(tmp);
	return (token);
}
