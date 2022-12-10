/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:42:26 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 23:22:54 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

int	error(char *message, int exit_code)
{
	printf(GREY"minishell: %s\n"RESET, message);
	g_minishell->last_exit_code = exit_code;
	return (exit_code);
}
