#include "minishell.h"

//var_name nome
char  **for_unset(char **envp, char *var_name)
{
  char **new_envp;
  char **temp_envp;
  size_t i;
  size_t k;
  size_t envp_size;

  envp_size = array_size(envp);
  temp_envp = (char **) malloc(sizeof(char *) * envp_size);

  temp_envp[envp_size] = NULL;

  i = 0;
  k = 0;
  if (var_name != NULL)
  {
    while(envp[i])
    {
      //envp[i] -> string de variavel de ambiente (nome=gabriel)
      if (!ft_strcmp(var_name, get_var_name(envp[i])))
      {
        temp_envp[k] = envp[i];
        k++;
      }
      i++;
    }
    return(temp_envp);
  }
  return (NULL);
}
