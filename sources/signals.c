/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/08 19:04:31 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

static void	handle_sigint(int signal);
void		handle_sigquit(int signal);
void		handle_sigint_fork(int signal);

void	handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_signal_fork(void)
{
	signal(SIGINT, handle_sigint_fork);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sigint_fork(int signal)
{
	(void) signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
}

static void	handle_sigint(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	printf(PURPLE);
	rl_on_new_line();
	rl_redisplay();
}
