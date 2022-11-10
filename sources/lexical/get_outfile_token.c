/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfile_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:48:48 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 06:52:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

t_token	*get_outfile_token(char *start, char **str)
{
	if (start && str && *str && *start == '>')
	{
		if (*(start + 1) == '>')
		{
			*str = start + 2;
			return (token_create(ft_strdup(">>"), OUTFILE_APPEND));
		}
		*str = start + 1;
		return (token_create(ft_strdup(">"), OUTFILE));
	}
	return (NULL);
}
