/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 14:12:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

void	syntax_clear(t_syntax *syntax)
{
	if (!syntax)
		return ;
	token_destroy(syntax->last_token);
	token_destroy(syntax->current_token);
	token_destroy(syntax->next_token);
	syntax->last_token = NULL;
	syntax->current_token = NULL;
	syntax->next_token = NULL;
}
