
#include "minishell.h"

char **set_env_value(char *name, char *value, char **envp)
{
  char	*var_name;
  char 	*new_name;
	char	**temp_envp;

	new_name = ft_strjoin(name, "=");
	var_name = ft_strjoin(new_name, value);
	free(new_name);
	if (envp)
		temp_envp = to_unset(envp, name);
	array_append(&temp_envp, var_name);
	return (temp_envp);
}
