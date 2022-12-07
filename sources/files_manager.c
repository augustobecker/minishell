/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:40:53 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/07 00:59:34 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static void		file_error_message(t_file	*file);
static int		read_heredoc(t_file *file, char *limiter);

void	init_files(t_list *list)
{
	t_cmd	*command;
	t_list	*node;
	size_t	i;

	i = 0;
	node = list;
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
	int		fd_stdout;
	char	*tmp_limiter;

	fd_stdout = dup(STDOUT_FILENO);
	dup2(file->fd, STDOUT_FILENO);
	tmp_limiter = ft_strjoin(limiter, "\n");
	line = get_next_line(STDIN_FILENO);
	while (!ft_strnstr(line, tmp_limiter, ft_strlen(tmp_limiter)))
	{
		printf("%s", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	free(tmp_limiter);
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
			break ;
		}
		node = node->next;
	}
}
