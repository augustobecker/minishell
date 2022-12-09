/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:26:07 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/09 21:01:05 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static t_bool	are_the_quotation_marks_closed(char *expression);
static t_bool	is_syntax_valid(char *expression);
static t_bool	validate_syntax_aux(char *expression);
static int		next_token(char *str);

t_bool	syntatic_validations(char *prompt)
{
	char	*tokenized_prompt;
	int		i;

	if (prompt == NULL)
		handle_sigquit(SIGQUIT);
	i = 0;
	while (prompt[i] && prompt[i] == ' ')
		i++;
	if (!prompt[i])
		return (false);
	if (!are_the_quotation_marks_closed(prompt))
	{
		error("syntax error: unclosed quotation marks", 2);
		return (false);
	}
	add_history(prompt);
	tokenized_prompt = tokenization(prompt);
	if (prompt[i] == '|' || !is_syntax_valid(tokenized_prompt))
	{
		free(tokenized_prompt);
		error("syntax error or syntax not suported", 2);
		return (false);
	}
	free(tokenized_prompt);
	return (true);
}

static t_bool	is_syntax_valid(char *expression)
{
	int		i;

	i = next_token(expression);
	while (expression[i])
	{
		if ((expression[i + 1] == '<') || (expression[i + 1] == '>')
			|| (expression[i + 1] == '|') || (expression[i + 1] == '&'))
		{
			if (expression[i] != expression[i + 1] || expression[i] == '|')
				return (false);
			i++;
		}
		if (expression[i] == '&')
			return (false);
		if (!validate_syntax_aux(&expression[i]))
			return (false);
		i++;
		i += next_token(&expression[i]);
	}
	return (true);
}

static t_bool	validate_syntax_aux(char *expression)
{
	int		i;

	i = 1;
	while (expression[i] && expression[i] == ' ')
		i++;
	if (expression[0] == '|' && expression[i] == '|')
		return (false);
	if (expression[0] != '|')
	{
		if ((expression[i] == '<')
			|| (expression[i] == '>')
			|| (expression[i] == '|')
			|| (expression[i] == '&'))
			return (false);
	}
	if (!expression[i])
		return (false);
	return (true);
}

static int	next_token(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '<')
			|| (str[i] == '>')
			|| (str[i] == '|')
			|| (str[i] == '&'))
			return (i);
		i++;
	}
	return (i);
}

static t_bool	are_the_quotation_marks_closed(char *expression)
{
	t_stack	**head;
	int		result;
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
	result = *head == NULL;
	clear_stack(head);
	return (result);
}
