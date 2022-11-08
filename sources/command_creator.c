/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_creator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:18:59 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/04 18:17:16 by gnuncio-         ###   ########.fr       */
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

char	*command_creator(char *prompt)
{
	int		i;
	char	*command;
	t_bool	replacement_status;
	t_stack	**head;

	replacement_status = true;
	head = malloc(sizeof(t_stack **));
	*head = NULL;
	command = ft_strdup(prompt);
	i = 0;
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
	free(head);
	return (command);
}
