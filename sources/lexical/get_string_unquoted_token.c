/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_unquoted_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:43:36 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 07:10:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token	*get_string_unquoted_token(char *start, char **str)
{
	char	*str_end;

	if (!start || !str || !*start || !*str)
		return (NULL);
	str_end = start;
	while (*str_end && !ft_strchr("<>|\"' ", *str_end))
		str_end++;
	*str = str_end;
	return (token_create(
			ft_substr(start, 0, str_end - start),
			STRING_UNQUOTED
		));
}
