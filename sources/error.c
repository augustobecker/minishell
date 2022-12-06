/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:42:26 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/06 12:30:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int	error(char *message, int exit_code)
{
	printf(GREY"minishell: %s\n"RESET, message);
	g_data.last_exit_code = exit_code;
	return (exit_code);
}
