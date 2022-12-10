/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:59:21 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/08 19:04:52 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void	execution_exit(void)
{
	clear_memory();
	array_destroy(g_minishell->envp);
	free(g_minishell->current_path);
	g_minishell->envp = NULL;
	free(g_minishell);
	exit (0);
}
