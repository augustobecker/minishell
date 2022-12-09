/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_syntax_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:45:50 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 14:25:50 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(syntax_checker);

TEST_SETUP(syntax_checker) {}
TEST_TEAR_DOWN(syntax_checker) {}

TEST(syntax_checker, Null_pointer_str)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker(NULL, &error));
	TEST_ASSERT_NULL(error);
}

TEST(syntax_checker, Empty_string)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker("", &error));
	TEST_ASSERT_NULL(error);
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" ", &error));
	TEST_ASSERT_NULL(error);
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker("   ", &error));
	TEST_ASSERT_NULL(error);
}

TEST(syntax_checker, Unclosed_quotation_marks)
{
	char *error;
	char *error_cmp = "Unclosed quotation marks";
	
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" 'teste' ", &error));
	TEST_ASSERT_NULL(error);

	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" \"teste\" ", &error));
	TEST_ASSERT_NULL(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" 'teste ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" ' ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" comando ' error ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" ''  ' ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" '\"cmd ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" '\" ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" comando \" error ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" \"\"  \" ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" 'ok' \"ok\"  \"error ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" 'ok' \"ok\"  'error ", &error));
	TEST_ASSERT_EQUAL_STRING(error_cmp, error);
	free(error);
}

TEST(syntax_checker, Invalid_infile_sequence)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" < ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: newline", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" < < ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: <", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" < << ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: <<", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" < | ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" << ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: newline", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" << << ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: <<", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" << < ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: <", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" << | ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);
}

TEST(syntax_checker, Valid_infile_sequence)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" < ok ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" < \"ok\" ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" < 'ok' ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" << ok ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" << \"ok\" ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" << 'ok' ", &error));
	TEST_ASSERT_NULL(error);
}

TEST(syntax_checker, Invalid_outfile_sequence)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" > ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: newline", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" > > ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: >", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" > >> ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: >>", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" > | ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" >> ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: newline", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" >> >> ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: >>", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" >> > ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: >", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" >> | ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);
}

TEST(syntax_checker, Valid_outfile_sequence)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" > ok ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" > \"ok\" ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" > 'ok' ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" >> ok ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" >> \"ok\" ", &error));
	TEST_ASSERT_NULL(error);
	TEST_ASSERT_EQUAL_INT(true, syntax_checker(" >> 'ok' ", &error));
	TEST_ASSERT_NULL(error);
}

TEST(syntax_checker, Invalid_pipe_sequence)
{
	char *error;
	
	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" | ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" | command ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" command || ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);

	TEST_ASSERT_EQUAL_INT(false, syntax_checker(" cmd | cmd || ", &error));
	TEST_ASSERT_EQUAL_STRING("Unexpected token: |", error);
	free(error);
}

TEST_GROUP_RUNNER(syntax_checker) {
	RUN_TEST_CASE(syntax_checker, Null_pointer_str);
	RUN_TEST_CASE(syntax_checker, Empty_string);
	RUN_TEST_CASE(syntax_checker, Unclosed_quotation_marks);
	RUN_TEST_CASE(syntax_checker, Invalid_infile_sequence);
	RUN_TEST_CASE(syntax_checker, Valid_infile_sequence);
	RUN_TEST_CASE(syntax_checker, Invalid_outfile_sequence);
	RUN_TEST_CASE(syntax_checker, Valid_outfile_sequence);
	RUN_TEST_CASE(syntax_checker, Invalid_pipe_sequence);
}