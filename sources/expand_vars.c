/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:32:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 09:53:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		append_str(char **dst, const char *src, size_t start, size_t s);
static size_t	append_var(char **dst, const char *prompt, char *const *envp);
static char		*get_var_name(const char *str);

// Replaces the $var declaration of prompt string to the respective
// value of the environment variable name.
char	*expand_vars(const char *prompt, char *const *envp)
{	
	char	*var_name;
	char	*var_value;
	char	*newstr;
	size_t	i;
	size_t	start_copy_index;

	if (!prompt)
		return (NULL);
	newstr = NULL;
	i = 0;
	start_copy_index = 0;
	while (prompt[i])
	{
		if (prompt[i] == '$' && ft_isalpha(prompt[i + 1]))
		{
			append_str(&newstr, prompt, start_copy_index, i - start_copy_index);
			i += append_var(&newstr, prompt + i + 1, envp);
			start_copy_index = i + 1;
		}
		i++;
	}
	append_str(&newstr, prompt, start_copy_index, i);
	return (newstr);
}

// Appends the src into dst and free the old dst content.
static void	append_str(char **dst, const char *src, size_t start, size_t len)
{
	char	*tmp;
	char	*substr;

	if (!dst || !src)
		return ;
	substr = ft_substr(src, start, len);
	if (!*dst)
	{
		(*dst) = ft_strjoin("", substr);
		free(substr);
		return ;
	}
	tmp = *dst;
	(*dst) = ft_strjoin(tmp, substr);
	free(substr);
	free(tmp);
}

// Append the variable value into dst and return de variable name size.
static size_t	append_var(char **dst, const char *prompt, char *const *envp)
{
	char	*var_name;
	char	*var_value;
	size_t	name_len;

	if (!dst || !prompt)
		return (0);
	var_name = get_var_name(prompt);
	var_value = get_env_value(var_name, envp);
	name_len = ft_strlen(var_name);
	free(var_name);
	if (var_value)
		append_str(dst, var_value, 0, ft_strlen(var_value));
	free(var_value);
	return (name_len);
}

// Return the variable name.
// It walk throwly the str and stops at the firt invalid 
// variable name character, returnign the catched characters.
static char	*get_var_name(const char *str)
{
	size_t	i;

	if (!str || !*str)
		return (ft_strdup(""));
	i = 0;
	while (str[i] && ft_isalnum(str[i]))
		i++;
	return (ft_substr(str, 0, i));
}
