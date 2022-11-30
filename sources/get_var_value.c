#include "minishell.h"

char	*get_var_value(const char *string)
{
	char	*value;

	if (!string)
		return(NULL);

	value = ft_strchr(string, '=');
	if(value != NULL)
		return (ft_substr(value, 1, ft_strlen(value -1)));
	return (NULL);
}