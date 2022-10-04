/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/04 14:16:54 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void);
char	*current_path(void);

void	prompt(void)
{
	char	*prompt;

	prompt = readline(current_path());
	if (is_prompt_valid(prompt) == false)
		exit(EXIT_FAILURE);
	if (ft_strlen(prompt) > 0)
		add_history(prompt);
	ft_printf(CYAN"prompt> %s\n"RESET, prompt);
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
