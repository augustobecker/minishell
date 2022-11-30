/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:42:26 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/30 22:48:58 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data g_data;

int	error(char *message, int exit_code)
{
	printf(GREY"minishell: %s\n"RESET, message);
	g_data.last_exit_code = exit_code;
	return (exit_code);
}
