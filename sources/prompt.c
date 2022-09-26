/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:26:52 by acesar-l          #+#    #+#             */
/*   Updated: 2022/09/26 19:50:18 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	char	*prompt;

	//Read, Evaluate and Print Loop (REPL)
	while (true)
	{
		// First, read
		prompt = readline(PURPLE"coder> "RESET);
		// Then evaluate, validate the arguments
		//
		// Print the output
		printf(CYAN"prompt> %s\n"RESET, prompt);
	}
}
