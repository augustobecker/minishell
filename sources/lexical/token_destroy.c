/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:25:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 06:52:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexical.h"

void	token_destroy(t_token *token)
{
	if (!token)
		return ;
	free(token->value);
	free(token);
}
