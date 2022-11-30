/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:40:30 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/14 17:24:38 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"
#include "lexical.h"

TEST_GROUP(get_next_token);

TEST_SETUP(get_next_token) {}
TEST_TEAR_DOWN(get_next_token) {}

TEST(get_next_token, Null_pointer)
{
	TEST_ASSERT_NULL(get_next_token(NULL));
}

TEST(get_next_token, Empty_string)
{
	char *str1 = "";
	TEST_ASSERT_NULL(get_next_token(&str1));
	
	char *str2 = "        ";
	TEST_ASSERT_NULL(get_next_token(&str2));
}

TEST(get_next_token, String_double_quoted_closed)
{
	char *str = " \"gabriel\" ";
	char *tmp = str + 10;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_DQ_CLOSED, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);
	
	token_destroy(token);

	str = " \"  | < << > >> ' '\" ";
	token = get_next_token(&str);
	
	TEST_ASSERT_EQUAL_STRING("  | < << > >> ' '", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_DQ_CLOSED, token->type);

	token_destroy(token);
}

TEST(get_next_token, String_double_quoted_unclosed)
{
	char *str = " \"gabriel | ' ' < << >> > ";
	char *tmp = str + 26;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel | ' ' < << >> > ", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_DQ_UNCLOSED, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, String_single_quoted_closed)
{
	char *str = " 'gabriel' ";
	char *tmp = str + 10;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_SQ_CLOSED, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, String_single_quoted_unclosed)
{
	char *str = " 'gabriel ";
	char *tmp = str + 10;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel ", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_SQ_UNCLOSED, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, Infile_common)
{
	char *str = " < ";
	char *tmp = str + 2;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("<", token->value);
	TEST_ASSERT_EQUAL_INT(INFILE, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, Infile_heredoc)
{
	char *str = " << ";
	char *tmp = str + 3;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("<<", token->value);
	TEST_ASSERT_EQUAL_INT(INFILE_HEREDOC, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, Outfile_common)
{
	char *str = " > ";
	char *tmp = str + 2;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING(">", token->value);
	TEST_ASSERT_EQUAL_INT(OUTFILE, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, Outfile_append)
{
	char *str = " >> ";
	char *tmp = str + 3;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING(">>", token->value);
	TEST_ASSERT_EQUAL_INT(OUTFILE_APPEND, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, String_unquoted)
{
	char *str = " gabriel ";
	char *tmp = str + 8;
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_UNQUOTED, token->type);
	TEST_ASSERT_POINTERS_EQUAL(tmp, str);

	token_destroy(token);
}

TEST(get_next_token, Multi_tokens)
{
	char *str = " gabriel | \"str\" '\"str_2\"'  ";
	t_token *token = get_next_token(&str);
	
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("gabriel", token->value);
	TEST_ASSERT_EQUAL_INT(STRING_UNQUOTED, token->type);
	token_destroy(token);

	token = get_next_token(&str);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_INT(PIPE, token->type);
	token_destroy(token);

	// token = get_next_token(&str);
	// TEST_ASSERT_NOT_NULL(token);
	// TEST_ASSERT_EQUAL_STRING("str", token->value);
	// TEST_ASSERT_EQUAL_INT(STRING_DQ_CLOSED, token->type);
	// token_destroy(token);

	// token = get_next_token(&str);
	// TEST_ASSERT_NOT_NULL(token);
	// TEST_ASSERT_EQUAL_STRING("\"str_2\"", token->value);
	// TEST_ASSERT_EQUAL_INT(STRING_SQ_CLOSED, token->type);
	// token_destroy(token);
}

// strings contendo caractes reservados
//		" | " "<  << > >>"

TEST_GROUP_RUNNER(get_next_token) {
	RUN_TEST_CASE(get_next_token, Null_pointer);
	RUN_TEST_CASE(get_next_token, Empty_string);
	RUN_TEST_CASE(get_next_token, String_double_quoted_closed);
	RUN_TEST_CASE(get_next_token, String_double_quoted_unclosed);
	RUN_TEST_CASE(get_next_token, String_single_quoted_closed);
	RUN_TEST_CASE(get_next_token, String_single_quoted_unclosed);
	RUN_TEST_CASE(get_next_token, Infile_common);
	RUN_TEST_CASE(get_next_token, Infile_heredoc);
	RUN_TEST_CASE(get_next_token, Outfile_common);
	RUN_TEST_CASE(get_next_token, Outfile_append);
	RUN_TEST_CASE(get_next_token, String_unquoted);
	RUN_TEST_CASE(get_next_token, Multi_tokens);
}