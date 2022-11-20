/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/20 14:03:15 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_a_builtin(char *command);
void	execute_builtin(t_cmd *command, char *const *envp);
int		pwd(void);
int		cd(char *directory, int argc, char *const *env);
int		echo(char **arguments);

t_bool	is_a_builtin(char *command)
{
	if ((ft_strcmp("echo\0", command))
		|| (ft_strcmp("cd\0", command))
		|| (ft_strcmp("pwd\0", command))
		|| (ft_strcmp("export\0", command))
		|| (ft_strcmp("unset\0", command))
		|| (ft_strcmp("env\0", command))
		|| (ft_strcmp("exit\0", command)))
		return (true);
	return (false);
}

void	execute_builtin(t_cmd *cmd, char *const *envp)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp("echo\0", cmd->command))
		exit_code = echo(&cmd->args[1]);
	else if (ft_strcmp("pwd\0", cmd->command))
		exit_code = pwd();
	else if (ft_strcmp("export\0", cmd->command))
		exit_code = ft_printf("expor not built\n");
	else if (ft_strcmp("unset\0", cmd->command))
		exit_code = ft_printf("unset not built\n");
	else if (ft_strcmp("env\0", cmd->command))
		exit_code = ft_printf("env not built\n");
	else
		exit (0);
	//free memory
	exit(exit_code);
}

int	pwd(void)
{
	char	*pwd;

	pwd = ft_calloc(sizeof(char), PATH_MAX + 1);
	if (getcwd(pwd, PATH_MAX) == NULL)
		return (1);
	else
	{
		ft_printf("%s\n", pwd);
		free(pwd);
		return (0);
	}
}

int	cd(char *directory, int argc, char *const *env)
{
	char	*home_dir;
	int		return_value;

	if (argc > 2)
	{
		ft_printf(GREY"minishell: cd : too many arguments\n"RESET);
		return (1);
	}
	if (argc == 1 || ft_strcmp("~\0", directory))
	{
		home_dir = get_env_value("HOME", env);
		if (!home_dir)
			return (1);
		return_value = cd(home_dir, argc, env);
		free(home_dir);
		return (return_value);
	}
	if (chdir(directory))
	{
		ft_printf(
			GREY"minishell: cd: %s: No such file or directory\n"RESET,
			directory);
		return (1);
	}
	return (0);
}

int	echo(char **arguments)
{
	t_bool	flag_n;
	size_t	args;
	int		i;

	i = 0;
	flag_n = false;
	if (*arguments == NULL)
		return (ft_printf("\n"));
	args = array_size(arguments);
	if (ft_strcmp("-n\0", arguments[0]))
	{
		flag_n = true;
		i++;
	}
	ft_printf("%s", arguments[i++]);
	while (i < args)
		ft_printf(" %s", arguments[i++]);
	if (!flag_n)
		ft_printf("\n");
	return (0);
}
