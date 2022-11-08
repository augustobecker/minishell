/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_env_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:52:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/03 14:16:43 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(get_env_value);

static char *envp[] = {"test=ok", "user=gabriel", NULL};

TEST_SETUP(get_env_value) {}
TEST_TEAR_DOWN(get_env_value) {}

static void check_is_null(char *name, char **envp)
{
	char *result = get_env_value(name, envp);
	TEST_ASSERT_NULL(get_env_value(NULL, envp));
	free(result);
}

TEST(get_env_value, Null_params) {
	char *empty_envp[] = {NULL};
	
	check_is_null("test", NULL);
	check_is_null("test", empty_envp);
	check_is_null(NULL, envp);
	check_is_null(NULL, NULL);
}

TEST(get_env_value, Name_not_defined) {
	check_is_null("", envp);
	check_is_null("test2", envp);
	check_is_null("not_exist", envp);
	check_is_null("use", envp);
}

TEST(get_env_value, Name_defined) {
	char *value;
	
	value = get_env_value("test", envp);
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ok", value);
	free(value);

	value = get_env_value("user", envp);
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("gabriel", value);
	free(value);
}

TEST_GROUP_RUNNER(get_env_value) {
	RUN_TEST_CASE(get_env_value, Null_params);
	RUN_TEST_CASE(get_env_value, Name_not_defined);
	RUN_TEST_CASE(get_env_value, Name_defined);
}