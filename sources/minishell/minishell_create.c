/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:35:31 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/08 17:46:35 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*minishell_create(char **envp)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (minishell)
	{
		minishell->current_path = NULL;
		minishell->envp = array_dup(envp);
		minishell->last_exit_code = 0;
		minishell->command_list = NULL;
		minishell->temp_infile = NULL;
		minishell->temp_outfile = NULL;
	}
	return (minishell);
}
