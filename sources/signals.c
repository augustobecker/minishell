/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:42:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/06 16:20:52 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

static void	handle_sigint(int signal);
void		handle_sigquit(int signal);

void	handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}

void	handle_sigquit(int signal)
{
	(void)signal;
	clear_history();
	clear_global();
	array_destroy(g_data.env);
	g_data.env = NULL;
	write(1, "exit\n", 5);
	exit (0);
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
