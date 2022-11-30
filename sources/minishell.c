/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:18:49 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/29 23:33:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_data;

// void printenvp(char **envp)
// {
// 	while(envp && *envp)
// 	{
// 		printf("%s\n", *envp);
// 		envp++;
// 	}
// }

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 || ft_strcmp(argv[0], "minishell"))
		exit(EXIT_FAILURE);
	g_data.env = array_dup(envp);
	// printenvp(envp);
	handle_signal();
	while (true)
	{
		prompt(&g_data);
	}
}
