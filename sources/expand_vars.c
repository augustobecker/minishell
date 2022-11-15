/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:32:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/15 09:37:12 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*var_name(const char *str);
static void		expand_token(t_token *token, char *const *envp);
static void		append_str(char **dst, const char *src, size_t start, size_t s);
static void		append_str(char **dst, const char *src, size_t start, size_t s);
static size_t	append_var(char **dst, const char *prompt, char *const *envp);

char	*expand_vars(const char *str, char *const *envp)
{
	char	*prompt;
	char	*result;
	t_token	*token;
	char	*tmp;

	if (!str)
		return (NULL);
	prompt = (char *) str;
	token = get_next_token(&prompt);
	result = NULL;
	while (token)
	{	
		if (result)
			append_str(&result, " ", 0, 2);
		if (is_valid_expand_vars_token(token->type))
			expand_token(token, envp);
		tmp = token_to_str(token);
		append_str(&result, tmp, 0, ft_strlen(tmp) + 1);
		token_destroy(token);
		free(tmp);
		token = get_next_token(&prompt);
	}
	token_destroy(token);
	return (result);
}

static void	expand_token(t_token *token, char *const *envp)
{
	char	*newstr;
	size_t	i;
	size_t	start_copy_at;

	newstr = NULL;
	start_copy_at = 0;
	i = 0;
	while (token->value[i])
	{
		if (token->value[i] == '$' && \
			(token->value[i + 1] == '_' || ft_isalpha(token->value[i + 1])))
		{
			append_str(&newstr, token->value, start_copy_at, i - start_copy_at);
			i += append_var(&newstr, token->value + i + 1, envp);
			start_copy_at = i + 1;
		}
		i++;
	}
	append_str(&newstr, token->value, start_copy_at, i);
	free(token->value);
	token->value = newstr;
}

static char	*var_name(const char *str)
{
	size_t	i;

	if (!str || !*str)
		return (ft_strdup(""));
	i = 0;
	while (str[i] && (str[i] == '_' || ft_isalnum(str[i])))
		i++;
	return (ft_substr(str, 0, i));
}

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

static size_t	append_var(char **dst, const char *prompt, char *const *envp)
{
	char	*name;
	char	*value;
	size_t	name_len;

	name_len = 0;
	if (dst && prompt)
	{
		name = var_name(prompt);
		value = get_env_value(name, envp);
		if (name)
			name_len = ft_strlen(name);
		if (value)
			append_str(dst, value, 0, ft_strlen(value));
		free(name);
		free(value);
	}
	return (name_len);
}
