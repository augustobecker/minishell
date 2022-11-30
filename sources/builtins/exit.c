/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:54 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/30 22:44:24 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

extern t_data g_data;

int	minishell_exit(t_list *list)
{
	clear_memory(list);
	exit (0);
}
