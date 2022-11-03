/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/03 12:11:02 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(int fd_out);
int	cd(char *directory);

int	pwd(int fd_out)
{
	char	*pwd;

	pwd = ft_calloc(sizeof(char), PATH_MAX);
	if (getcwd(pwd, PATH_MAX) == NULL)
		return (1);
	else
	{
		if (fd_out != STDOUT_FILENO)
			dup2(fd_out, STDOUT_FILENO);
		ft_printf("%s\n", pwd);
		free(pwd);
		return (0);
	}
}

int	cd(char *directory)
{
	if (directory == NULL || directory[0] == '\0')
		return (chdir("/home"));
	if (chdir(directory))
	{
		ft_printf(GREY"minishell: cd: %s: No such file or directory\n"RESET, directory);
		return (1);
	}
	else
		return (0);
}
