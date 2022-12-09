/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:00:04 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 14:09:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

void	syntax_init(t_syntax *syntax, char **error)
{
	if (!syntax)
		return ;
	syntax->last_token = NULL;
	syntax->current_token = NULL;
	syntax->next_token = NULL;
	syntax->error = error;
	(*syntax->error) = NULL;
}
