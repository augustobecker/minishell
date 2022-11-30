/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unset_env_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:22:49 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/29 23:23:01 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(unset_env_value);

TEST_SETUP(unset_env_value) {}
TEST_TEAR_DOWN(unset_env_value) {}

TEST(unset_env_value, with_null_envp)
{
	char **new_array = unset_env_value("USER", NULL);
	
	TEST_ASSERT_NULL(new_array);
}

TEST(unset_env_value, with_empty_envp)
{
	char *envp[] = {NULL};
	char **new_array = unset_env_value("USER", envp);

	TEST_ASSERT_NOT_NULL(new_array);
	TEST_ASSERT_EQUAL_INT(0, array_size(new_array));

	array_destroy(new_array);
}


TEST(unset_env_value, with_absent_env_var)
{
	char *envp[] = {"PATH=/home", NULL};
	char **copy = array_dup(envp);
	char **new_array = unset_env_value("USER", copy);

	TEST_ASSERT_NOT_NULL(new_array);
	TEST_ASSERT_EQUAL_INT(1, array_size(new_array));
	TEST_ASSERT_EQUAL_STRING("PATH=/home", envp[0]);
	TEST_ASSERT_NULL(envp[1]);

	array_destroy(copy);
	free(new_array);
}

TEST(unset_env_value, with_present_env_var)
{
	char *envp[] = {"USER=gabriel", "PATH=/home", "OTHER=test", NULL};
	char **copy = array_dup(envp);
	char **new_array = unset_env_value("OTHER", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(2, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=gabriel", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("PATH=/home", new_array[1]);
	TEST_ASSERT_NULL(new_array[2]);

	array_destroy(copy);
	free(new_array);
}


TEST_GROUP_RUNNER(unset_env_value)
{
	RUN_TEST_CASE(unset_env_value, with_null_envp);
	RUN_TEST_CASE(unset_env_value, with_empty_envp);
	RUN_TEST_CASE(unset_env_value, with_absent_env_var);
	RUN_TEST_CASE(unset_env_value, with_present_env_var);
}