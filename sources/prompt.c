/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/29 22:50:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"

void	prompt(t_data *data);
char	*current_path(void);
void 	print_list(t_list *list);
void	print_cmd(t_cmd *cmd);

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

static void prompt_null(char *prompt, char *path)
{
	if (prompt == NULL)
	{
		free(path);
		free(prompt);
		exit(0);
	}
}

void	prompt(t_data *data)
{
	char	*prompt;
	char	*path;
	char	*prompt_exp;
	char	**commands;
	t_list	*list;

	path = current_path();
	prompt = readline(path);

	if (prompt == NULL)
		prompt_null(prompt, path);
	if (syntatic_validations(prompt) == false) // Token + sintaxe
		return;
	prompt_exp = expand_vars(prompt, data->env);
	//print_tokens_colorized(prompt_exp);
	commands = parse_pipe(prompt_exp);
	list = cmd_create_list(commands);
	// print_list(list);
	init_global_struct();
	init_files(list);
	execution_process(list);
	clear_memory(list);
	free(prompt_exp);
	free(path);
}

// void print_list(t_list *list)
// {
// 	t_list	*node;
// 	t_cmd	*cmd;

// 	while (list)
// 	{
// 		cmd = (t_cmd *) list->content;
		
// 		if (cmd)
// 		{
// 			print_cmd(cmd);
// 			printf("\n");
// 		}
			
// 		list = list->next;
// 	}
// }

// void	print_cmd(t_cmd *cmd)
// {
// 	if (!cmd)
// 		return ;
	
// 	printf("Comando: %s\n", cmd->command);
// 	printf("\tArgs: "); array_print(cmd->args);
	
// 	if (cmd->infile)
// 	{
// 		printf("\tInfile: %s | ", cmd->infile->path);
// 		printf("%s\n", (cmd->infile->type == COMMON_FILE_IN)? "COMMON":"HEREDOC");
// 	}
// 	else 
// 		printf("\tInfile: null\n");
		
// 	if (cmd->outfile)
// 	{
// 		printf("\tOutfile: %s | ", cmd->outfile->path);
// 		printf("%s\n", (cmd->outfile->type == COMMON_FILE_OUT)? "COMMON":"APPEND");
// 	}
// 	else 
// 		printf("\tOutfile: null\n");
// }

char	*current_path(void)
{
	char	*path;

	path = ft_calloc(sizeof(char), PATH_MAX + 1);
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
