/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_outfile_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:24:38 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 09:24:54 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_outfile_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == OUTFILE)
		return (true);
	if (token->type == OUTFILE_APPEND)
		return (true);
	return (false);
}
