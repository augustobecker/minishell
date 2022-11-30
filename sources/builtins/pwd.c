/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/30 13:54:05 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(void)
{
	char	*pwd;

	pwd = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (getcwd(pwd, PATH_MAX) == NULL)
		return (1);
	else
	{
		printf("%s\n", pwd);
		free(pwd);
		return (0);
	}
}
