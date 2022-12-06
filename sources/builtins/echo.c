/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:02 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/06 13:37:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **arguments)
{
	t_bool	flag_n;
	size_t	args;
	size_t	i;

	i = 0;
	flag_n = false;
	if (*arguments == NULL)
		return (printf("\n"));
	args = array_size(arguments);
	if (ft_strcmp("-n\0", arguments[0]))
	{
		flag_n = true;
		i++;
	}
	printf("%s", arguments[i++]);
	while (i < args)
		printf(" %s", arguments[i++]);
	if (!flag_n)
		printf("\n");
	return (0);
}
