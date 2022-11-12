/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:22:51 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 09:23:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_string_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == STRING_UNQUOTED)
		return (true);
	if (token->type == STRING_DQ_CLOSED)
		return (true);
	if (token->type == STRING_DQ_CLOSED)
		return (true);
	if (token->type == STRING_SQ_CLOSED)
		return (true);
	if (token->type == STRING_SQ_CLOSED)
		return (true);
	return (false);
}
