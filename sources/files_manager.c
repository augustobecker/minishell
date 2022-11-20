/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:15:15 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/20 02:19:50 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_files(t_data *data, t_list *list)
{
	t_cmd  *command;
	t_list *node;

	file_destroy(&data->empty_infile);
	data->empty_infile = file_create(EMPTY_INFILE, 0, COMMON_FILE_IN);
	data->empty_infile->fd = open(EMPTY_INFILE, O_RDONLY | O_CREAT | O_TRUNC, 0644);
	file_destroy(&data->discarded_outfile);
	data->discarded_outfile = file_create("TMP_OUTFILE", 0, COMMON_FILE_OUT);
	data->discarded_outfile->fd = open(TMP_OUTFILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	node = list;
	while (node)
	{
		command = (t_cmd *) node->content;
		file_manager(data, command->infile);
		file_manager(data, command->outfile);
		node = node->next;
	}
}

static void	file_error_message(t_data *data, t_file	*file)
{
	if (file->type == COMMON_FILE_IN)
	{
		if (access(file->path, R_OK))
			ft_printf(GREY"minishell: %s : Permission denied\n"RESET, file->path);
		else
			ft_printf(GREY"minishell: %s : No such file or directory\n"RESET, file->path);
		file->fd = data->empty_infile->fd;
	}
	else
	{
		ft_printf(GREY"minishell: %s : Permission denied\n"RESET, file->path);
		file->fd = data->discarded_outfile->fd;
	}
}

void	file_manager(t_data *data, t_file	*file)
{
	if (file == NULL)
		return ;
	else if (file->type == COMMON_FILE_IN)
	{
		file->fd = open(file->path, O_RDONLY);
		if (file->fd == -1)
			file_error_message(data, file);
	}
	else if (file->type == COMMON_FILE_OUT)
	{
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			file_error_message(data, file);
	}
	else if (file->type == APPEND_FILE)
	{
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			file_error_message(data, file);
	}
	else if (file->type == HEREDOC_FILE)
		file->fd = open("/tmp/herecdoc_minihell", O_WRONLY | O_CREAT | \
				O_APPEND, 0644);
}
