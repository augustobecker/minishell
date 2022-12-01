/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:18:59 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/01 22:10:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	replacement(t_stack **stack, char character)
{
	if (character == '\'' || character == '"')
	{
		if (!(*stack))
			stack_push(stack, stack_new(character));
		else if ((*stack)->c == character)
		{
			stack_pop(stack);
			return (true);
		}
		else if ((*stack)->c != character)
		{
			stack_push(stack, stack_new(character));
			return (false);
		}
	}
}

char	*replace_pipe(char *command, t_stack **head)
{
	int		i;
	t_bool	replacement_status;

	i = 0;
	replacement_status = true;
	while (command[i])
	{
		if (command[i] == '\'' || command[i] == '"')
			replacement_status = replacement(head, command[i]);
		if ((*head) && (command[i] != '\'') && (command[i] != '"'))
		{
			i++;
			continue ;
		}
		if (command[i] == '|' && replacement_status == true)
			command[i] = '&';
		i++;
	}
}

char	**parse_pipe(char *prompt)
{
	int		i;
	char	*command;
	char	**list_commands;
	t_stack	**head;

	if (!prompt)
		return (NULL);
	head = malloc(sizeof(t_stack **));
	if (!head)
		return (NULL);
	*head = NULL;
	command = ft_strdup(prompt);
	replace_pipe(command, head);
	free(head);
	list_commands = ft_split(command, '&');
	free (command);
	return (list_commands);
}
