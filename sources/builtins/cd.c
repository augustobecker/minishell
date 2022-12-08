/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:59:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/07 23:29:14 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_minishell	*g_minishell;

int			cd(char **args, int argc);
static int	cd_to_home(void);

int	cd(char **args, int argc)
{
	if (argc > 2)
	{
		printf(GREY"minishell: cd : too many arguments\n"RESET);
		return (1);
	}
	else if (argc == 1)
		return (cd_to_home());
	else if (ft_strcmp("~", args[1]))
		return (cd_to_home());
	else if (chdir(args[1]))
	{
		printf(GREY"minishell: cd: %s: No such file or directory\n"RESET,
			args[1]);
		return (1);
	}
	return (0);
}

static int	cd_to_home(void)
{
	char	*home_dir;

	home_dir = get_env_value("HOME", g_minishell->envp);
	if (!home_dir)
	{
		printf(GREY"minishell: cd : HOME not set\n"RESET);
		free(home_dir);
		return (1);
	}
	else if (chdir(home_dir))
	{
		printf(
			GREY"minishell: cd: %s: No such file or directory\n"RESET,
			home_dir
			);
		free(home_dir);
		return (1);
	}
	free(home_dir);
	return (0);
}
