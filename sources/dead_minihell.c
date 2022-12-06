/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_minihell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:02:25 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/06 16:11:32 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	dead_minihell(t_list *list)
{
	clear_history();
	clear_memory(list);
	array_destroy(g_data.env);
	g_data.env = NULL;
	exit (0);
}
