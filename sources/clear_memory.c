/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:51:57 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 23:20:24 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

int	clear_memory(void)
{
	t_cmd	*command;
	t_list	*node;

	node = g_minishell->command_list;
	clear_global();
	delete_temporary_files();
	while (node)
	{
		command = (t_cmd *)node->content;
		cmd_destroy(&command);
		node = node->next;
	}
	if (g_minishell->command_list == NULL)
		return (g_minishell->last_exit_code);
	list_clear(&g_minishell->command_list);
	return (g_minishell->last_exit_code);
}
