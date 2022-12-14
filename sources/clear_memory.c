/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:51:57 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 13:33:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

int	clear_memory(t_list *list)
{
	t_cmd	*command;
	t_list	*node;

	node = list;
	clear_global();
	delete_temporary_files();
	while (node)
	{
		command = (t_cmd *)node->content;
		cmd_destroy(&command);
		node = node->next;
	}
	list_clear(&list);
	return (g_data.last_exit_code);
}
