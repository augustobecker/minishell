

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(for_unset);

TEST_SETUP(for_unset) {}
TEST_TEAR_DOWN(for_unset) {}

TEST(for_unset, main)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = for_unset(copy, "DOG");

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(2, array_size(new_array));

	TEST_ASSERT_EQUAL_STRING("USER=Usuário", new_array[0]);
	TEST_ASSERT_EQUAL_STRING("ADVOGATO=Gato", new_array[1]);
	TEST_ASSERT_NULL(new_array[2]);
}

TEST(for_unset, Invalid_name)
{

	char *envp[] = {"USER=Usuário", "DOG=Cachorro", "ADVOGATO=Gato", NULL};
	char **copy = array_dup(envp);
	char **new_array = for_unset(copy, "ADVODOG");

	TEST_ASSERT_EQUAL_INT(3, array_size(copy));
	TEST_ASSERT_EQUAL_INT(3, array_size(new_array));
}


TEST_GROUP_RUNNER(for_unset)
{
	RUN_TEST_CASE(for_unset, main);
	RUN_TEST_CASE(for_unset, Invalid_name);
}