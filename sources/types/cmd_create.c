/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:24:24 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/08 22:34:18 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_create(const char *cmd, char *const *args, t_file *in, t_file *out)
{
	t_cmd	*command;

	command = (t_cmd *) malloc(sizeof(t_cmd));
	if (command)
	{
		command->command = ft_strdup(cmd);
		command->args = array_dup(args);
		command->infile = in;
		command->outfile = out;
	}
	return (command);
}
