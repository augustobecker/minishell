/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/07 16:39:15 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	syntax_checker(const char *str, char **error)
{
	t_token *current_token;
	char	*copy_str;

	*error = NULL;
	if (!str)
		return (false);

	copy_str = ft_strdup(str);
	current_token = get_next_token(&copy_str);

	if (!current_token)
		return (false);

	while (current_token)
	{
		if (current_token->type == STRING_DQ_UNCLOSED || current_token->type == STRING_SQ_UNCLOSED)
		{
			token_destroy(current_token);
			*error = "Unclosed quotation marks";
			return (false);
			break;
		}
		token_destroy(current_token);
		current_token = get_next_token(&copy_str);
	}

	return (true);
}