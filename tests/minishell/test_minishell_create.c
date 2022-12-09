/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:33:42 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/07 15:34:17 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(minishell_create);

TEST_SETUP(minishell_create) {}
TEST_TEAR_DOWN(minishell_create) {}

TEST(minishell_create, Null_envp)
{
	char *envp[] = {NULL};

	t_minishell *minishell;

	minishell = minishell_crate(envp);


	TEST_ASSERT_NULL(minishell->envp[0]);
	array_destroy(minishell->envp);
	free(minishell);

}

TEST(minishell_create, Create)
{
	char *envp[] = {"PATH=/home","USER=guilherme", "NEON=thron", NULL};


	t_minishell *minishell;

	minishell = minishell_crate(envp);

	TEST_ASSERT_EQUAL_STRING("PATH=/home", minishell->envp[0]);
	TEST_ASSERT_EQUAL_STRING("USER=guilherme", minishell->envp[1]);
	TEST_ASSERT_EQUAL_STRING("NEON=thron", minishell->envp[2]);
	TEST_ASSERT_NULL(minishell->envp[3]);


	array_destroy(minishell->envp);
	free(minishell);
}

TEST_GROUP_RUNNER(minishell_create)
{
	RUN_TEST_CASE(minishell_create, Create);
	RUN_TEST_CASE(minishell_create, Null_envp);
}