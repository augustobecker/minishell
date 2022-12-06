/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:42:24 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/06 12:34:48 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	init_global_struct(void)
{
	g_data.last_exit_code = 0;
	if (g_data.empty_infile)
		file_destroy(&g_data.empty_infile);
	g_data.empty_infile = file_create(EMPTY_INFILE, 0, COMMON_FILE_IN);
	if (g_data.discarded_outfile)
		file_destroy(&g_data.discarded_outfile);
	g_data.discarded_outfile = file_create("TMP_OUTFILE", 0, COMMON_FILE_OUT);
	g_data.empty_infile->fd = \
	open(EMPTY_INFILE, O_RDONLY | O_CREAT | O_TRUNC, 0644);
	g_data.discarded_outfile->fd = \
	open(TMP_OUTFILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	clear_global(void)
{
	file_destroy(&g_data.empty_infile);
	g_data.empty_infile = NULL;
	file_destroy(&g_data.discarded_outfile);
	g_data.discarded_outfile = NULL;
	free(g_data.prompt_path);
	g_data.prompt_path = NULL;
}
