/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infile_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:23:53 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 09:24:17 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_infile_token(t_token *token)
{
	if (!token)
		return (false);
	if (token->type == INFILE)
		return (true);
	if (token->type == INFILE_HEREDOC)
		return (true);
	return (false);
}
