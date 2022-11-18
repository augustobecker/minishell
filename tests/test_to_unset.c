

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(to_unset);

TEST_SETUP(to_unset) {}
TEST_TEAR_DOWN(to_unset) {}

TEST(to_unset, main)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = to_unset(copy, "DOG");

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(2, array_size(new_array));//deveria ter 2

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("ADVOGATO=Gato", new_array[1]);
	//TEST_ASSERT_EQUAL_STRING("", new_array[2]);
	TEST_ASSERT_NULL(new_array[2]);
	//array_print(new_array);
}

TEST(to_unset, Invalid_name)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = to_unset(copy, "ADVODOG");

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));
	//array_print(new_array);
}

TEST(to_unset, Invalid_array)
{

	char *envp[] = {NULL};
	char **copy = array_dup(envp);
	char **new_array = to_unset(copy, "ADVODOG");

	TEST_ASSERT_EQUAL_INT(0, array_size(copy));
	TEST_ASSERT_EQUAL_INT(0, array_size(new_array));
	//array_print(new_array);
}

TEST_GROUP_RUNNER(to_unset)
{
	RUN_TEST_CASE(to_unset, main);
	RUN_TEST_CASE(to_unset, Invalid_name);
	RUN_TEST_CASE(to_unset, Invalid_array);
}