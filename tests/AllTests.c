/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/16 16:51:55 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(get_env_value);
	// RUN_TEST_GROUP(parse_pipe);
	RUN_TEST_GROUP(expand_vars);
	RUN_TEST_GROUP(cmd_parse_str);
	RUN_TEST_GROUP(get_next_token);
	RUN_TEST_GROUP(get_var_name);
	RUN_TEST_GROUP(get_var_value);
	// RUN_TEST_GROUP(for_unset);
	RUN_TEST_GROUP(token_to_str);
	RUN_TEST_GROUP(array_append);
	RUN_TEST_GROUP(file_manager);
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
