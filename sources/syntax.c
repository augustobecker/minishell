/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:26:07 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/20 15:27:50 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_syntax_valid(char *expression);
t_bool	there_is_a_valid_char(char *str, char *limiter);
t_bool	is_a_limiter(char c);
t_bool	are_the_quotation_marks_closed(char *expression);

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
	t_stack    *new;

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
	t_stack    *new_first_node;

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

t_bool	is_syntax_valid(char *expression)
{
	int	i;

	i = 0;
	while (expression[i])
	{
		if (is_a_limiter(expression[i]) == true)
		{
			if (is_a_limiter(expression[i + 1]) == false)
			{
				if (expression[i] == '&')
					return (false);
			}
			else
			{
				if (expression[i] != expression[i + 1])
					return (false);
				i++;
			}
			i++;
			if (there_is_a_valid_char(&expression[i], "<|&>") == false)
				return (false);
		}
		i++;
	}
	return (true);
}

// Valida se existe algum caracter valido até a proxima ocorrencia de outro limitador
t_bool	there_is_a_valid_char(char *str, char *limiter)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (limiter[0] != '\0')
		{
			j = 0;
			while (limiter[j])
			{
				if (str[i] == limiter[j])
					return (false);
				j++;
			}
		}
		if ((str[i] != TAB) && (str[i] != SPACE))
			return (true);
		i++;
	}
	return (false);
}

t_bool	is_a_limiter(char c)
{
	if ((c == '<') || (c == '>') || (c == '|') || (c == '&'))
		return (true);
	return (false);
}

t_bool	are_the_quotation_marks_closed(char *expression)
{
	t_stack	**head;
	int		i;

	i = 0;
	head = malloc(sizeof(t_stack **));
	*head = NULL;
	while (expression[i])
	{
		if (expression[i] == '\'' || expression[i] == '"')
		{
			if (!(*head))
				stack_push(head, stack_new(expression[i]));
			else if ((*head)->c == expression[i])
				stack_pop(head);
			else if ((*head)->c != expression[i])
				stack_push(head, stack_new(expression[i]));
		}
		i++;
	}
	if (*head)
	{
		clear_stack(head);
		return (false);
	}
	clear_stack(head);
	return (true);
}

