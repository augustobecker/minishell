/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/28 13:20:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_a_builtin(char *command)
{
	if ((ft_strcmp("echo\0", command))
		|| (ft_strcmp("cd\0", command))
		|| (ft_strcmp("pwd\0", command))
		|| (ft_strcmp("export\0", command))
		|| (ft_strcmp("unset\0", command))
		|| (ft_strcmp("env\0", command))
		|| (ft_strcmp("exit\0", command)))
		return (true);
	return (false);
}
