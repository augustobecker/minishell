/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:22:02 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/06 12:23:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(const char *string)
{
	char	*value;

	if (!string)
		return (NULL);
	value = ft_strchr(string, '=');
	if (value)
		return (ft_substr(value, 1, ft_strlen(value -1)));
	return (NULL);
}
