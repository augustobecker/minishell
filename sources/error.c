/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:42:26 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/19 05:46:18 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error(char *message, int exit_code)
{
	ft_printf(GREY"minishell: %s\n"RESET, message);
	return (exit_code);
}
