/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:51:57 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/29 22:46:21 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

void        clear_memory(t_list *list);

void clear_memory(t_list *list)
{
    t_cmd		*command;
    t_list      *node;

    node = list;
    clear_global();
    delete_temporary_files(list);
    while (node)
    {
        command = (t_cmd *)node->content;
        cmd_destroy(&command);
        node = node->next;
    }
    list_clear(&list);
}
