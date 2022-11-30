/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:12:10 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/09 08:24:34 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_strcmp(const char *str1, const char *str2)
{
	return (ft_strncmp(str1, str2, ft_strlen(str2) + 1) == 0);
}
