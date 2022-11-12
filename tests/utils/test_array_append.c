/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:31:28 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 14:49:58 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(array_append);

TEST_SETUP(array_append) {}
TEST_TEAR_DOWN(array_append) {}

TEST(array_append, Null_array)
{
	char **array = NULL;
	TEST_ASSERT_EQUAL_INT(0, array_size(array));
	
	array_append(&array, ft_strdup("Gabriel"));
	TEST_ASSERT_EQUAL_INT(1, array_size(array));
	TEST_ASSERT_EQUAL_STRING("Gabriel", array[0]);
	TEST_ASSERT_NULL(array[1]);

	array_destroy(array);
}

TEST(array_append, Having_one_string)
{
	char *base[] = {"Gabriel", NULL};
	char **array = array_dup(base);
	TEST_ASSERT_EQUAL_INT(1, array_size(array));
	
	array_append(&array, ft_strdup("Outro"));
	TEST_ASSERT_EQUAL_INT(2, array_size(array));
	TEST_ASSERT_EQUAL_STRING("Gabriel", array[0]);
	TEST_ASSERT_EQUAL_STRING("Outro", array[1]);
	TEST_ASSERT_NULL(array[2]);

	array_destroy(array);
}

TEST(array_append, Having_two_strings)
{
	char *base[] = {"Gabriel", "Outro", NULL};
	char **array = array_dup(base);
	TEST_ASSERT_EQUAL_INT(2, array_size(array));
	
	array_append(&array, ft_strdup("Nome"));
	TEST_ASSERT_EQUAL_INT(3, array_size(array));
	TEST_ASSERT_EQUAL_STRING("Gabriel", array[0]);
	TEST_ASSERT_EQUAL_STRING("Outro", array[1]);
	TEST_ASSERT_EQUAL_STRING("Nome", array[2]);
	TEST_ASSERT_NULL(array[3]);

	array_destroy(array);
}

TEST(array_append, Having_three_strings)
{
	char *base[] = {"Gabriel", "Outro", "Nome", NULL};
	char **array = array_dup(base);
	TEST_ASSERT_EQUAL_INT(3, array_size(array));
	
	array_append(&array, ft_strdup("OK"));
	TEST_ASSERT_EQUAL_INT(4, array_size(array));
	TEST_ASSERT_EQUAL_STRING("Gabriel", array[0]);
	TEST_ASSERT_EQUAL_STRING("Outro", array[1]);
	TEST_ASSERT_EQUAL_STRING("Nome", array[2]);
	TEST_ASSERT_EQUAL_STRING("OK", array[3]);
	TEST_ASSERT_NULL(array[4]);

	array_destroy(array);
}

TEST_GROUP_RUNNER(array_append)
{
	RUN_TEST_CASE(array_append, Null_array);
	RUN_TEST_CASE(array_append, Having_one_string);
	RUN_TEST_CASE(array_append, Having_two_strings);
	RUN_TEST_CASE(array_append, Having_three_strings);
}