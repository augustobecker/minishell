/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:48:42 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/11 19:49:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *cmd_create_list(char *const *cmds)
{
	t_list	*list_cmds;
	t_list	*node;
	t_cmd	*cmd;
	
	list_cmds = NULL;
	while(cmds && *cmds)
	{
		cmd = cmd_parse_str(*cmds);		// TODO Pode ser NULL
		node = ft_lstnew(cmd);			// TODO Pode ser NULL
		
		if(list_cmds == NULL)
			list_cmds = node;
		else
			ft_lstadd_back(&list_cmds, node);
		cmds++;
	}
	return (list_cmds);
}