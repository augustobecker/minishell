
#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(get_var_name);
TEST_SETUP(get_var_name) {}
TEST_TEAR_DOWN(get_var_name) {}

TEST(get_var_name, Null_pointer)
{
	TEST_ASSERT_NULL(get_var_name(NULL));
}

TEST(get_var_name, With_valid_var_name)
{
	char *name = get_var_name("nome=guilherme");

	TEST_ASSERT_NOT_NULL(name);
	TEST_ASSERT_EQUAL_STRING("nome", name);
	free(name);

	name = get_var_name("PATH=/home");

	TEST_ASSERT_NOT_NULL(name);
	TEST_ASSERT_EQUAL_STRING("PATH", name);
	free(name);
}

TEST(get_var_name, With_invalid_var_name)
{
	TEST_ASSERT_NULL(get_var_name("nome"));
}

TEST_GROUP_RUNNER(get_var_name)
{
	RUN_TEST_CASE(get_var_name, Null_pointer);
	RUN_TEST_CASE(get_var_name, With_valid_var_name);
	RUN_TEST_CASE(get_var_name, With_invalid_var_name);
}