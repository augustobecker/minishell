/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:32:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 08:46:29 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_vars(const char *prompt, char *const *envp)
{	
	size_t	i;
	size_t	b;
	size_t	start;
	char	*buff;
	char	*var_name;
	char	*var_value;
	char	*newstr;

	if (!prompt)
		return (NULL);
	buff = ft_calloc(4096, sizeof(char));
	i = 0;
	b = 0;
	while (prompt && prompt[i])
	{
		if (prompt[i] == '$' && ft_isalpha(prompt[i + 1]))
		{
			start = ++i;
			while (ft_isalnum(prompt[i]))
				i++;
			var_name = ft_substr(prompt, start, i - start);
			var_value = get_env_value(var_name, envp);
			free(var_name);
			if (var_value)
				b += ft_strlcpy(buff + b, var_value, ft_strlen(var_value) + 1);
			free(var_value);
			continue ;
		}
		buff[b++] = prompt[i];
		i++;
	}
	newstr = ft_strdup(buff);
	free(buff);
	return (newstr);
}
