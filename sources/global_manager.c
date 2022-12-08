/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:42:24 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 23:23:09 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void	init_global_struct(void)
{
	g_minishell->last_exit_code = 0;
	if (g_minishell->last_exit_code)
		file_destroy(&g_minishell->temp_outfile);
	g_minishell->temp_outfile = file_create("TMP_OUTFILE", 0, COMMON_FILE_OUT);
	g_minishell->temp_outfile->fd = \
	open(TMP_OUTFILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	clear_global(void)
{
	file_destroy(&g_minishell->temp_outfile);
	file_destroy(&g_minishell->temp_infile);
	g_minishell->temp_outfile = NULL;
	g_minishell->temp_infile = NULL;
	free(g_minishell->current_path);
	g_minishell->current_path = NULL;
}
