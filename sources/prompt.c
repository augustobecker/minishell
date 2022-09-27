/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/09/27 22:50:31 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(t_data *data, char **envp)
{
	char	*prompt;

	prompt = readline(PURPLE"coders> "RESET);
	if (is_prompt_valid(prompt) == false)
		exit(EXIT_FAILURE);
	if (ft_strlen(prompt) > 0)
		add_history(prompt);
	ft_printf(CYAN"prompt> %s\n"RESET, prompt);
}
