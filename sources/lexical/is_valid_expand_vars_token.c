/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_expand_vars_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:34:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/15 09:39:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_valid_expand_vars_token(t_tokentype type)
{
	if (type == STRING_DQ_CLOSED)
		return (true);
	if (type == STRING_DQ_UNCLOSED)
		return (true);
	if (type == STRING_UNQUOTED)
		return (true);
	return (false);
}
