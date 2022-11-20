/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:56 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/20 21:34:28 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				pwd(void);
int				cd(char *directory, int argc, char *const *env);
int				echo(char **arguments);
static void		print_echo(char *str);

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
	print_echo(arguments[i++]);
	while (i < args)
		print_echo(arguments[i++]);
	if (!flag_n)
		ft_printf("\n");
	return (0);
}

static void	print_echo(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] != '\\')
			i++;
		ft_printf("%c", str[i]);
		i++;
	}
	ft_printf(" ");
}
