/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/01 15:44:57 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *pwd(void)
{
	char	*pwd;

	pwd = ft_calloc(1, 100);
	getcwd(pwd, 100);
	ft_printf(PURPLE);
	pwd = ft_strappend(&pwd, ">");
	pwd = ft_strappend(&pwd, " ");
	pwd = ft_strappend(&pwd, RESET);
	return (pwd);
}
