/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/07 15:04:47 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(get_env_value);
	//RUN_TEST_GROUP(parse_pipe);
	RUN_TEST_GROUP(expand_vars);
	RUN_TEST_GROUP(cmd_parse_str);
	RUN_TEST_GROUP(get_next_token);
	RUN_TEST_GROUP(get_var_name);
	RUN_TEST_GROUP(get_var_value);
	RUN_TEST_GROUP(token_to_str);
	RUN_TEST_GROUP(array_append);
	//RUN_TEST_GROUP(file_manager);
	RUN_TEST_GROUP(unset_env_value);
	RUN_TEST_GROUP(set_env_value);
	RUN_TEST_GROUP(minishell_create);

}

t_data	g_data;

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
