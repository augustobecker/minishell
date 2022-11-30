/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/28 13:20:46 by gasouza          ###   ########.fr       */
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
		ft_printf("%s\n", pwd);
		free(pwd);
		return (0);
	}
}
