/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/11 19:45:21 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int signal);

void	handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	ft_printf(PURPLE);
	rl_on_new_line();
	rl_redisplay();
}
