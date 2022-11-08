/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:24:24 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/08 17:58:48 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*command_create(void)
{
	t_command	*cmd;

	cmd = (t_command *) malloc(sizeof(t_command));
	if (cmd)
	{
		cmd->command = NULL;
		cmd->args = NULL;
		cmd->infile = NULL;
		cmd->outfile = NULL;
		cmd->exit_code = FALSE;
		cmd->is_append = FALSE;
		cmd->is_heredoc = FALSE;
	}
	return (cmd);
}
