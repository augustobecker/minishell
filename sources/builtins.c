/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/04 14:37:56 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_printf("%s", pwd);
		return (0);
	}
}
