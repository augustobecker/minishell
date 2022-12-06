/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:18:49 by acesar-l          #+#    #+#             */
/*   Updated: 2022/12/05 21:45:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 || ft_strcmp(argv[0], "minishell"))
		exit(EXIT_FAILURE);

	g_data.empty_infile = NULL;
	g_data.discarded_outfile = NULL;
	g_data.prompt_path = NULL;

	
	g_data.env = array_dup(envp);
	handle_signal();
	while (true)
	{
		prompt();
	}
}
