/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_minihell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:02:25 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/05 22:01:40 by gasouza          ###   ########.fr       */
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
