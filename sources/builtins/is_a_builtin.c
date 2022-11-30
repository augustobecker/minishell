/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 22:30:37 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_a_builtin(char *command)
{
	if ((ft_strcmp("echo", command))
		|| (ft_strcmp("cd", command))
		|| (ft_strcmp("pwd", command))
		|| (ft_strcmp("export", command))
		|| (ft_strcmp("unset", command))
		|| (ft_strcmp("env", command))
		|| (ft_strcmp("exit", command)))
		return (true);
	return (false);
}
