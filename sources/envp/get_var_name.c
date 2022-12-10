/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:13:32 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/06 13:21:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(const char *string)
{
	char	*equal_char_at;

	if (!string)
		return (NULL);
	equal_char_at = ft_strchr(string, '=');
	if (equal_char_at)
		return (ft_substr(string, 0, equal_char_at - string));
	return (NULL);
}
