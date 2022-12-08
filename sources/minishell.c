/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:18:49 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/08 18:21:36 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*g_minishell;

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 || ft_strcmp(argv[0], "minishell"))
		exit(EXIT_FAILURE);
	g_minishell = minishell_create(envp);
	handle_signal();
	while (true)
		prompt();
}
