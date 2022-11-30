/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:13:32 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/11 17:42:54 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// usuario=gabriel  -> usuario
char	*get_var_name(const char *string)
{
	char *var_name;
	char *equal_char_at;

	if(string == NULL)
		return (NULL);

	equal_char_at = ft_strchr(string, '=');
	if (equal_char_at)
	{
		return ft_substr(string, 0, equal_char_at - string);
	}

	return (NULL);
}

