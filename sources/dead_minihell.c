/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_minihell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:02:25 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/07 23:22:19 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void	dead_minihell(void)
{
	clear_history();
	clear_memory();
	array_destroy(g_minishell->envp);
	free(g_minishell->current_path);
	g_minishell->envp = NULL;
	free(g_minishell);
	exit (0);
}
