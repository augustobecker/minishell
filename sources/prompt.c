/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/08 14:02:37 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void);
char	*current_path(void);

void	prompt(void)
{
	char	*prompt;
	char	*token_prompt;
	char	*current;
	char	**command_line;

	current = current_path();

	prompt = readline(current);
	free(current);
	if (ft_strnstr(prompt, "command", ft_strlen(prompt)))
	{
		command_line = parse_pipe(prompt);
		printf("%s\n", command_line[0]);
		printf("%s\n", command_line[1]);
		array_destroy(command_line);
		return;
	}
	if (there_is_a_valid_char(prompt, "\0") == false)
		return	;
	if (are_the_quotation_marks_closed(prompt) == false)
	{
		error("syntax error: unclosed quotation marks", 2);
		return	;
	}
	add_history(prompt);
	if (there_is_a_valid_char(prompt, "#") == false)
		return	;
	token_prompt = tokenization(prompt);
	if (is_syntax_valid(token_prompt) == false)
		error("syntax error or syntax not suported", 2);
	free(token_prompt);
	if (is_prompt_valid(prompt) == false)
		exit(EXIT_FAILURE);
	if (ft_strnstr(prompt, "cd", ft_strlen(prompt)))
		cd(&prompt[3]);
	if (ft_strnstr(prompt, "echo", ft_strlen(prompt)))
		ft_printf("%s\n", &prompt[5]);
	if (ft_strnstr(prompt, "pwd", ft_strlen(prompt)))
		pwd(STDOUT_FILENO);
	if (ft_strnstr(prompt, "exit", ft_strlen(prompt)))
	{
		free(prompt);
		error("Saindo",0);
	}
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
