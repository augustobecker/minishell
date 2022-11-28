/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:02 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/28 12:58:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char *str);

int	echo(char **arguments)
{
	t_bool	flag_n;
	size_t	args;
	int		i;

	i = 0;
	flag_n = false;
	if (*arguments == NULL)
		return (ft_printf("\n"));
	args = array_size(arguments);
	if (ft_strcmp("-n\0", arguments[0]))
	{
		flag_n = true;
		i++;
	}
	print_echo(arguments[i++]);
	while (i < args)
		print_echo(arguments[i++]);
	if (!flag_n)
		ft_printf("\n");
	return (0);
}

static void	print_echo(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			i++;
		ft_printf("%c", str[i]);
		i++;
	}
	ft_printf(" ");
}
