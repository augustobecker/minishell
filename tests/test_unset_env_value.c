

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(unset_env_value);

TEST_SETUP(unset_env_value) {}
TEST_TEAR_DOWN(unset_env_value) {}

TEST(unset_env_value, main)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = unset_env_value("DOG", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(2, array_size(new_array));//deveria ter 2

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("ADVOGATO=Gato", new_array[1]);
	//TEST_ASSERT_EQUAL_STRING("", new_array[2]);
	TEST_ASSERT_NULL(new_array[2]);
	//array_print(new_array);
}

TEST(unset_env_value, Invalid_name)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = unset_env_value("ADVODOG", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));
	//array_print(new_array);
}

TEST(unset_env_value, Invalid_array)
{

	char *envp[] = {NULL};
	char **copy = array_dup(envp);
	char **new_array = unset_env_value("ADVODOG", copy);

	TEST_ASSERT_EQUAL_INT(0, array_size(copy));
	TEST_ASSERT_EQUAL_INT(0, array_size(new_array));
	//array_print(new_array);
}

TEST_GROUP_RUNNER(unset_env_value)
{
	RUN_TEST_CASE(unset_env_value, main);
	RUN_TEST_CASE(unset_env_value, Invalid_name);
	RUN_TEST_CASE(unset_env_value, Invalid_array);
}