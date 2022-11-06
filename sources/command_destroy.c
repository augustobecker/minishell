/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:43:24 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/06 19:49:28 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_destroy(t_command **cmd)
{
	if (!cmd || !*cmd)
		return ;
	free((*cmd)->command);
	array_destroy((*cmd)->args);
	free((*cmd)->infile);
	free((*cmd)->outfile);
	free(*cmd);
	*cmd = NULL;
}
