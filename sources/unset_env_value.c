/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:16:59 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 22:21:56 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//var_name nome
char  **unset_env_value(const char *name, char *const *envp)
{
  char **new_envp;
  char **temp_envp;
  size_t i;
  size_t k;
  size_t envp_size;

  envp_size = array_size(envp);
  temp_envp = (char **) malloc(sizeof(char *) * (envp_size));
  temp_envp[envp_size] = NULL;
  i = 0;
  k = 0;
  if (envp == NULL)
    return NULL;
  if (name != NULL)
  {
    while(envp[i])
    {
      if (!ft_strcmp(name, get_var_name(envp[i])))
      {
        temp_envp[k] = envp[i];
        k++;
      }
    i++;
    }
    temp_envp[k] = NULL;
    return(temp_envp);
  }
  return (NULL);
}
