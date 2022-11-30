

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(get_var_value);
TEST_SETUP(get_var_value) {}
TEST_TEAR_DOWN(get_var_value) {}

TEST(get_var_value, Null_pointer)
{
	TEST_ASSERT_NULL(get_var_value(NULL));
}

TEST(get_var_value, With_valid_var_value)
{
	char *value = get_var_value("nome=guilherme");

	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("guilherme", value);
	free(value);

	value = get_var_value("PATH=/home");

	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("/home", value);
	free(value);
}


TEST(get_var_value, With_empty_value)
{
	char *value = get_var_value("nome=");

	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("", value);
	free(value);
}

TEST(get_var_value, With_invalid_var_value)
{
	TEST_ASSERT_NULL(get_var_value("nome"));
}

TEST_GROUP_RUNNER(get_var_value)
{
	RUN_TEST_CASE(get_var_value, Null_pointer);
	RUN_TEST_CASE(get_var_value, With_valid_var_value);
	RUN_TEST_CASE(get_var_value, With_empty_value);
	RUN_TEST_CASE(get_var_value, With_invalid_var_value);
}