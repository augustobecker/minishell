/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:23 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/05 21:49:12 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void		execution_process(t_list *list);
static void	execute_single_cmd(t_cmd *command, int fd_pipe_in, t_list *list);
static int	execute_cmd_to_pipe(t_cmd *command, int fd_pipe_in, t_list *list);
static int	execute(t_cmd *command);
static void	command_not_found(char *command, t_list *list);

void	execution_process(t_list *list)
{
	t_cmd		*command;
	t_list		*node;
	int			fd_pipe_in;

	node = list;
	fd_pipe_in = g_data.empty_infile->fd;
	while (node)
	{
		command = (t_cmd *) node->content;
		if (ft_strcmp("exit", command->command))
			dead_minihell(list);
		if ((ft_strcmp("cd", command->command))
		|| (ft_strcmp("export", command->command))
		|| (ft_strcmp("unset", command->command)))
			execute_builtin(command);
		else if ((!node->next) || (command->outfile))
		{
			execute_single_cmd(command, fd_pipe_in, list);
			fd_pipe_in = g_data.empty_infile->fd;
		}
		else
			fd_pipe_in = execute_cmd_to_pipe(command, fd_pipe_in, list);
		node = node->next;
	}
}

static void	execute_single_cmd(t_cmd *command, int fd_pipe_in, t_list *list)
{
	int	pid;
	int wstatus;

	pid = fork();
	if (pid == 0)
	{
		clear_history();
		if (command->infile)
			dup2(command->infile->fd, STDIN_FILENO);
		else
			dup2(fd_pipe_in, STDIN_FILENO);
		if (command->outfile)
			dup2(command->outfile->fd, STDOUT_FILENO);
		if (execute(command) == -1)
			command_not_found(command->command, list);
		exit (clear_memory(list));
	}
	else
	{
		waitpid(pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			g_data.last_exit_code = WEXITSTATUS(wstatus);
	}
}

static int	execute_cmd_to_pipe(t_cmd *command, int fd_pipe_in, t_list *list)
{
	int	fd_new_pipe[2];
	int wstatus;
	int	pid;

	pipe(fd_new_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(fd_new_pipe[INPUT]);
		if (command->infile)
			dup2(command->infile->fd, STDIN_FILENO);
		else
			dup2(fd_pipe_in, STDIN_FILENO);
		dup2(fd_new_pipe[OUTPUT], STDOUT_FILENO);
		if (execute(command) == -1)
			command_not_found(command->command, list);
		exit (clear_memory(list));
	}
	else
	{
		waitpid(pid, &wstatus, 0);
		if (WIFEXITED(wstatus))
			g_data.last_exit_code = WEXITSTATUS(wstatus);
		close(fd_new_pipe[OUTPUT]);
		return (fd_new_pipe[INPUT]);
	}
}

static int	execute(t_cmd *command)
{
	char	*cmd_and_path;
	char	**paths;
	int		i;

	i = 0;
	if ((ft_strcmp("echo", command->command))
		|| (ft_strcmp("pwd", command->command))
		|| ((ft_strcmp("env", command->command))))
	{
			g_data.last_exit_code = execute_builtin(command);
			return (0);
	}
	if (ft_count_occurrences(command->command, '/'))
		execve(command->command, command->args, g_data.env);
	paths = get_cmd_paths();
	while (paths && paths[i])
	{
		cmd_and_path = ft_strjoin(paths[i], command->command);
		execve(cmd_and_path, command->args, g_data.env);
		free(cmd_and_path);
		i++;
	}
	array_destroy(paths);
	return (-1);
}

static void	command_not_found(char *command, t_list *list)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf(GREY"minishell: %s : command not found\n"RESET, command);
	g_data.last_exit_code = COMMAND_NOT_FOUND;
	clear_memory(list);
}
