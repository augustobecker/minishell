/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:02 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 22:31:35 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **arguments)
{
	t_bool	flag_n;
	size_t	args;
	int		i;

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
