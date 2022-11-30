/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:43:24 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/08 21:40:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_destroy(t_cmd **cmd)
{
	if (!cmd || !*cmd)
		return ;
	free((*cmd)->command);
	array_destroy((*cmd)->args);
	file_destroy(&(*cmd)->infile);
	file_destroy(&(*cmd)->outfile);
	free(*cmd);
	*cmd = NULL;
}
