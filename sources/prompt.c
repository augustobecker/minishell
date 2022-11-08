/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/08 17:33:30 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_data *data);
char	*current_path(void);
void print_cmds(char **cmds);

void array_print(char **envp)
{
	while(envp && *envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}

t_bool syntatic_validations(char *prompt)
{
	if (there_is_a_valid_char(prompt, "\0") == false)
		return	(false);
	if (are_the_quotation_marks_closed(prompt) == false)
	{
		error("syntax error: unclosed quotation marks", 2);
		return	(false);
	}
	add_history(prompt);
	if (there_is_a_valid_char(prompt, "#") == false)
		return	(false);
	if (ft_strcmp(prompt, "exit") == true)
	{
		free(prompt);
		exit(0);
	}
	return (true);
}

void	prompt(t_data *data)
{
	char	*prompt;
	char	*path;
	char	*prompt_exp;
	char	**commands;


	path = current_path();
	prompt = readline(path);

	if (syntatic_validations(prompt) == false) // Token + sintaxe
		return;
	prompt_exp = expand_vars(prompt, data->env); // PATH, USERNAME, PAPERSIZE, GDMSESSION
	commands = parse_pipe(prompt_exp);

	array_print(commands);

	print_cmds(commands);

	array_destroy(commands);




	free(prompt_exp);
	free(path);
}

char	*current_path(void)
{
	char	*path;

	path = ft_calloc(sizeof(char), PATH_MAX);
	if (getcwd(path, PATH_MAX) == NULL)
		return (NULL);
	else
	{
		ft_printf(PURPLE);
		path = ft_strappend(&path, ">");
		path = ft_strappend(&path, " ");
		path = ft_strappend(&path, RESET);
		return (path);
	}
}


void print_cmds(char **cmds)
{
	t_command *cmd;

	while (cmds && *cmds)
	{
		cmd = command_parse_str(*cmds);
		if (cmd)
		{
			char **args;
			printf("Comando: %s\n", cmd->command);
			printf("Args: ");

			args = cmd->args;
			while(args && *args)
			{
				printf("%s ", *args);
				args++;
			}

			printf("\n");
			printf("Infile: %s | Heredoc: %d\n", cmd->infile, cmd->is_heredoc);
			printf("Outfile: %s | Append: %d\n\n", cmd->outfile, cmd->is_append);
		}
		command_destroy(&cmd);
		cmds++;
	}
}

	// char	*prompt;
	// char	*token_prompt;
	// char	*current;
	// char	**command_line;

	// current = current_path();

	// prompt = readline(current);
	// free(current);
	// if (ft_strnstr(prompt, "command", ft_strlen(prompt)))
	// {
	// 	command_line = parse_pipe(prompt);
	// 	printf("%s\n", command_line[0]);
	// 	printf("%s\n", command_line[1]);
	// 	array_destroy(command_line);
	// 	return;
	// }
	// if (is_prompt_valid(prompt) == false)
	// 	exit(EXIT_FAILURE);
	// if (ft_strnstr(prompt, "cd", ft_strlen(prompt)))
	// 	cd(&prompt[3]);
	// if (ft_strnstr(prompt, "echo", ft_strlen(prompt)))
	// 	ft_printf("%s\n", &prompt[5]);
	// if (ft_strnstr(prompt, "pwd", ft_strlen(prompt)))
	// 	pwd(STDOUT_FILENO);


