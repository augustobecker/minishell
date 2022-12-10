/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/01 21:44:54 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tokenization(char *prompt)
{
	t_stack	**head;
	char	*token;
	int		i;

	i = 0;
	token = ft_strdup(prompt);
	head = malloc(sizeof(t_stack **));
	*head = NULL;
	while (token[i])
	{
		if (token[i] == '\'' || token[i] == '"')
		{
			if (!(*head))
				stack_push(head, stack_new(token[i]));
			else if ((*head)->c == token[i])
				stack_pop(head);
			else if ((*head)->c != token[i])
				stack_push(head, stack_new(token[i]));
		}
		if ((*head) && (token[i] != '\'') && (token[i] != '"'))
			token[i] = '*';
		i++;
	}
	clear_stack(head);
	return (token);
}
