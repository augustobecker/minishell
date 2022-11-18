
#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(set_env_value);

TEST_SETUP(set_env_value) {}
TEST_TEAR_DOWN(set_env_value) {}

TEST(set_env_value, swap_value)
{
	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = set_env_value("DOG", "Meg", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("ADVOGATO=Gato", new_array[1]);
  TEST_ASSERT_EQUAL_STRING("DOG=Meg", new_array[2]);
	TEST_ASSERT_NULL(new_array[3]);
	//array_print(new_array);
}

TEST(set_env_value, new_name)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = set_env_value("ADVODOG", "Meg", copy);

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(4, array_size(new_array));
}

TEST(set_env_value, array_null)
{

	char *envp[] = {NULL};
	char **copy = array_dup(envp);
	char **new_array = set_env_value("ADVODOG", "Meg", copy);

	TEST_ASSERT_EQUAL_INT(0, array_size(copy));
	TEST_ASSERT_EQUAL_INT(1, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("ADVODOG=Meg", new_array[0]);
	TEST_ASSERT_NULL(new_array[1]);
}


TEST_GROUP_RUNNER(set_env_value)
{
	RUN_TEST_CASE(set_env_value, swap_value);
	RUN_TEST_CASE(set_env_value, array_null);
	RUN_TEST_CASE(set_env_value, new_name);
}