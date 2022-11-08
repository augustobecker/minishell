/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:43 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/04 12:02:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(expand_vars);

static char *envp[] = {"test=ok", "user=gabriel", NULL};

TEST_SETUP(expand_vars) {}
TEST_TEAR_DOWN(expand_vars) {}

TEST(expand_vars, Null_params)
{
	TEST_ASSERT_NULL(expand_vars(NULL, NULL));
	TEST_ASSERT_NULL(expand_vars(NULL, envp));

	char *value = expand_vars("user", NULL);
	TEST_ASSERT_EQUAL_STRING("user", value);
	free(value);
}

TEST(expand_vars, Without_var)
{
	char *value;
	
	value = expand_vars("whith ou var", envp);
	TEST_ASSERT_EQUAL_STRING("whith ou var", value);
	free(value);

	value = expand_vars("user user test", envp);
	TEST_ASSERT_EQUAL_STRING("user user test", value);
	free(value);
}

TEST(expand_vars, With_invalid_var_name)
{
	char *value;
	
	value = expand_vars("invalid $ $$", envp);
	TEST_ASSERT_EQUAL_STRING("invalid $ $$", value);
	free(value);
}

TEST(expand_vars, With_valid_var_name)
{
	char *value;
	
	value = expand_vars("valid $user", envp);
	TEST_ASSERT_EQUAL_STRING("valid gabriel", value);
	free(value);

	value = expand_vars("valid $user and valid $test!", envp);
	TEST_ASSERT_EQUAL_STRING("valid gabriel and valid ok!", value);
	free(value);
	
	value = expand_vars("$user $test $ $invalid!", envp);
	TEST_ASSERT_EQUAL_STRING("gabriel ok $ !", value);
	free(value);
}

// variavel com nome contendo _

TEST_GROUP_RUNNER(expand_vars)
{
	RUN_TEST_CASE(expand_vars, Null_params);
	RUN_TEST_CASE(expand_vars, Without_var);
	RUN_TEST_CASE(expand_vars, With_invalid_var_name);
	RUN_TEST_CASE(expand_vars, With_valid_var_name);
}