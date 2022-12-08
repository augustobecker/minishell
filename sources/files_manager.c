/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:40:53 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/08 00:07:16 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

static void		file_error_message(t_file	*file);
static int		read_heredoc(t_file *file, char *limiter);

void	init_files(void)
{
	t_cmd	*command;
	t_list	*node;
	size_t	i;

	i = 0;
	node = g_minishell->command_list;
	while (node)
	{
		command = (t_cmd *) node->content;
		if (!command->infile && i == 0)
			command->infile = file_create("", STDIN_FILENO, COMMON_FILE_IN);
		else
			file_manager(command->infile);
		file_manager(command->outfile);
		node = node->next;
		i++;
	}
}

void	file_manager(t_file	*file)
{
	if (!file)
		return ;
	if (file->type == HEREDOC_FILE)
	{
		file->fd = open(HEREDOC_PATH, O_WRONLY | O_CREAT | O_APPEND, 0644);
		file->fd = read_heredoc(file, file->path);
		return ;
	}
	if (file->type == COMMON_FILE_IN)
		file->fd = open(file->path, O_RDONLY);
	if (file->type == COMMON_FILE_OUT)
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file->type == APPEND_FILE)
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file->fd == -1)
		file_error_message(file);
}

static int	read_heredoc(t_file *file, char *limiter)
{
	char	*line;

	line = readline("> ");
	while (!ft_strcmp(line, limiter))
	{
		ft_putendl_fd(line, file->fd);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(file->fd);
	return (open(HEREDOC_PATH, O_RDONLY));
}

static void	file_error_message(t_file *file)
{
	if (file->type == COMMON_FILE_IN)
	{
		if (access(file->path, F_OK) == -1)
			printf \
			(GREY"minishell: %s : No such file or directory\n"RESET, file->path);
		else if (access(file->path, R_OK) == -1)
			printf \
			(GREY"minishell: %s : Permission denied\n"RESET, file->path);
		file->fd = g_minishell->temp_infile->fd;
	}
	else
	{
		if (access(file->path, W_OK) == -1)
			printf(GREY"minishell: %s : Permission denied\n"RESET, file->path);
		file->fd = g_minishell->temp_infile->fd;
	}
}

void	delete_temporary_files(void)
{
	unlink(TMP_OUTFILE);
	unlink(HEREDOC_PATH);
}
