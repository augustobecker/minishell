/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:40:53 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/05 21:54:40 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void			init_files(t_list *list);
void			file_manager(t_file	*file);
static void		file_error_message(t_file	*file);
static int				read_heredoc(t_file *file, char *limiter);
void			delete_temporary_files(t_list *list);

void	init_files(t_list *list)
{
	t_cmd	*command;
	t_list	*node;

	node = list;
	while (node)
	{
		command = (t_cmd *) node->content;
		file_manager(command->infile);
		file_manager(command->outfile);
		node = node->next;
	}
}

void	file_manager(t_file	*file)
{
	if (file == NULL)
		return ;
	else if (file->type == COMMON_FILE_IN)
	{
		file->fd = open(file->path, O_RDONLY);
		if (file->fd == -1)
			file_error_message(file);
	}
	else if (file->type == COMMON_FILE_OUT)
	{
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			file_error_message(file);
	}
	else if (file->type == APPEND_FILE)
	{
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file->fd == -1)
			file_error_message(file);
	}
	else if (file->type == HEREDOC_FILE)
	{
		file->fd = open(HEREDOC_PATH, O_WRONLY | O_CREAT | \
				O_APPEND, 0644);
		file->fd = read_heredoc(file, file->path);
	}
}

static int	read_heredoc(t_file *file, char *limiter)
{
	char	*line;
    int		rd;
	int		fd_stdout;

	fd_stdout = dup(STDOUT_FILENO);
	dup2(file->fd, STDOUT_FILENO);
	limiter = ft_strappend(&limiter, "\n");
	line = get_next_line(STDIN_FILENO);
	while (!ft_strnstr(line, limiter, ft_strlen(limiter)))
	{
		printf("%s", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	dup2(fd_stdout, STDOUT_FILENO);
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
		file->fd = g_data.empty_infile->fd;
	}
	else
	{
		if (access(file->path, W_OK) == -1)
			printf(GREY"minishell: %s : Permission denied\n"RESET, file->path);
		file->fd = g_data.discarded_outfile->fd;
	}
}

void	delete_temporary_files(t_list *list)
{
	t_cmd	*command;
	t_list	*node;

	unlink(EMPTY_INFILE);
	unlink(TMP_OUTFILE);
	node = list;
	while (node && node->content)
	{
		command = (t_cmd *) node->content;
		if (command && command->infile && command->infile->type == HEREDOC_FILE)
		{
			unlink(HEREDOC_PATH);
			break;
		}
		node = node->next;
	}
}
