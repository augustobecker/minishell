/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:23 by acesar-l         #+#    #+#             */
/*   Updated: 2022/11/18 17:34:41 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    execution_process(t_data *data, t_list *list);
void    execute_single_cmd(t_data *data, t_cmd *command, int fd_pipe_in);
int     execute_cmd_to_pipe(t_data *data, t_cmd *command, int fd_pipe_in);
int     execute(t_cmd *command, char *const *envp);

void execution_process(t_data *data, t_list *list)
{
    t_cmd   *command;
    t_list  *node;
    int      fd_pipe_in;
    
    node = list;
	fd_pipe_in = data->empty_infile->fd;
    while (node)
    {
        command = (t_cmd *) node->content;
        if ((!node->next) || (command->outfile))
		{
            execute_single_cmd(data, command, fd_pipe_in);
			fd_pipe_in = data->empty_infile->fd;
		}
        else
            fd_pipe_in = execute_cmd_to_pipe(data, command, fd_pipe_in);
        node = node->next;
    }
}

void execute_single_cmd(t_data *data, t_cmd *command, int fd_pipe_in)
{
    int pid;

	pid = fork();
	if (pid == 0)
	{
		if (command->infile)
			dup2(command->infile->fd, STDIN_FILENO);
		else
			dup2(fd_pipe_in, STDIN_FILENO);
		if (command->outfile)
			dup2(command->outfile->fd, STDOUT_FILENO);
		if (execute(command, data->env) == -1) // free_all_memory();
		    command_not_found(command->command);
	}
	else
		waitpid(pid, NULL, 0);
}

int	execute_cmd_to_pipe(t_data *data, t_cmd *command, int fd_pipe_in)
{
	int	fd_new_pipe[2];
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
		if (execute(command, data->env) == -1)
		    command_not_found(command->command);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd_new_pipe[OUTPUT]);
        return (fd_new_pipe[INPUT]);
	}
}

int	execute(t_cmd *command, char *const *envp)
{
	char	*cmd_and_path;
	char	**paths;
	int		i;
	i = 0;
	if (ft_count_occurrences(command->command, '/') > 1)
		execve(command->command, command->args, envp);
	paths = get_cmd_paths(envp);
	while (paths[i])
	{
		cmd_and_path = ft_strjoin(paths[i], command->command);
		execve(cmd_and_path, command->args, envp);
		free(cmd_and_path);
		i++;
    }
    array_destroy(paths);
    return (-1);
}