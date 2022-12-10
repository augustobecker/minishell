/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 07:20:31 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/29 22:49:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_clear(t_list **list);

void	list_clear(t_list **list)
{
	t_list	*ptr_i;
	t_list	*next;

	ptr_i = *list;
	if (*list == NULL)
		return ;
	while (ptr_i)
	{
		next = ptr_i->next;
		free(ptr_i);
		ptr_i = next;
	}
	*list = NULL;
}

void	clear_stack(t_stack **stack)
{
	t_stack	*ptr_i;
	t_stack	*next;

	if (*stack == NULL)
	{
		free(stack);
		return ;
	}
	ptr_i = *stack;
	while (ptr_i)
	{
		next = ptr_i->next;
		free(ptr_i);
		ptr_i = next;
	}
	*stack = NULL;
	free(stack);
}

t_stack	*stack_new(char c)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}

void	stack_push(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	stack_pop(t_stack **stack)
{
	t_stack	*new_first_node;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	new_first_node = (*stack)->next;
	free(*stack);
	*stack = new_first_node;
}
