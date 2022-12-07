/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_last_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:57:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/07 00:05:01 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_data;

void	save_last_exit_code(int wstatus)
{
	char	**tmp_env;
	char	*num_str;

	if (WIFEXITED(wstatus))
	{
		g_data.last_exit_code = WEXITSTATUS(wstatus);
		tmp_env = g_data.env;
		num_str = ft_itoa(g_data.last_exit_code);
		g_data.env = set_env_value("?", num_str, tmp_env);
		array_destroy(tmp_env);
		free(num_str);
	}
}
