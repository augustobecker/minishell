
#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(set_env_value);

TEST_SETUP(set_env_value) {}
TEST_TEAR_DOWN(set_env_value) {}


TEST(set_env_value, with_null_pointer_envp)
{
	char **new_array = set_env_value("USER", "gabriel", NULL);

	TEST_ASSERT_EQUAL_INT(1, array_size(new_array));
	TEST_ASSERT_EQUAL_STRING("USER=gabriel", new_array[0]);
	TEST_ASSERT_NULL(new_array[1]);

	array_destroy(new_array);
}

TEST(set_env_value, with_empty_array)
{
	char *envp[] = {NULL};
	char **new_array = set_env_value("USER", "gabriel", envp);

	TEST_ASSERT_EQUAL_INT(0, array_size(envp));
	TEST_ASSERT_EQUAL_INT(1, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=gabriel", new_array[0]);
	TEST_ASSERT_NULL(new_array[1]);

	array_destroy(new_array);
}


TEST(set_env_value, replace_value)
{
	char *envp[] = {"USER=Usuário", "PATH=/home", "OTHER=old", NULL};
	char **copy = array_dup(envp);
	char **new_array = set_env_value("OTHER", "new", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(envp));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("PATH=/home", new_array[1]);
	TEST_ASSERT_EQUAL_STRING("OTHER=new", new_array[2]);
	TEST_ASSERT_NULL(new_array[3]);

	array_destroy(copy);
	array_destroy(new_array);
}

TEST(set_env_value, add_new_var)
{
	char *envp[] = {"USER=Usuário", "PATH=/home", NULL};
	char **copy = array_dup(envp);
	char **new_array = set_env_value("OTHER", "value", copy);

	TEST_ASSERT_EQUAL_INT(2, array_size(envp));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("PATH=/home", new_array[1]);
	TEST_ASSERT_EQUAL_STRING("OTHER=value", new_array[2]);
	TEST_ASSERT_NULL(new_array[3]);

	array_destroy(copy);
	array_destroy(new_array);
}

TEST_GROUP_RUNNER(set_env_value)
{
	RUN_TEST_CASE(set_env_value, with_null_pointer_envp);
	RUN_TEST_CASE(set_env_value, with_empty_array);
	RUN_TEST_CASE(set_env_value, replace_value);
	RUN_TEST_CASE(set_env_value, add_new_var);
}