/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:59:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/28 13:20:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char *directory, int argc, char *const *env)
{
	char	*home_dir;
	int		return_value;

	if (argc > 2)
	{
		ft_printf(GREY"minishell: cd : too many arguments\n"RESET);
		return (1);
	}
	if (argc == 1 || ft_strcmp("~", directory))
	{
		home_dir = get_env_value("HOME", env);
		if (!home_dir)
			return (1);
		return_value = cd(home_dir, argc, env);
		free(home_dir);
		return (return_value);
	}
	if (chdir(directory))
	{
		ft_printf(
			GREY"minishell: cd: %s: No such file or directory\n"RESET,
			directory);
		return (1);
	}
	return (0);
}
