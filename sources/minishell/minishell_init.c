/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:35:50 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/08 17:41:33 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

void	minishell_init_files(void)
{
	g_minishell->last_exit_code = 0;
	if (g_minishell->temp_outfile)
		file_destroy(&g_minishell->temp_outfile);
	g_minishell->temp_outfile = file_create("TMP_OUTFILE", 0, COMMON_FILE_OUT);
	g_minishell->temp_outfile->fd = \
	open(TMP_OUTFILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	init_files();
}
