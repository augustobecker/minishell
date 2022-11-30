/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_token_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:52:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 08:52:56 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(token_to_str);

static t_token	*token = NULL;
static char		*str = NULL;

TEST_SETUP(token_to_str) {}
TEST_TEAR_DOWN(token_to_str)
{
	token_destroy(token);
	free(str);
}

TEST(token_to_str, Null_token)
{
	TEST_ASSERT_NULL(token_to_str(NULL));
}

TEST(token_to_str, String_unquoted)
{
	token = token_create("gabriel", STRING_UNQUOTED);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("gabriel", str);
}

TEST(token_to_str, String_double_quoted_closed)
{
	token = token_create("gabriel", STRING_DQ_CLOSED);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("\"gabriel\"", str);
}

TEST(token_to_str, String_double_quoted_unclosed)
{
	token = token_create("gabriel", STRING_DQ_UNCLOSED);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("\"gabriel", str);
}

TEST(token_to_str, String_single_quoted_closed)
{
	token = token_create("gabriel", STRING_SQ_CLOSED);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("'gabriel'", str);
}

TEST(token_to_str, String_single_quoted_unclosed)
{
	token = token_create("gabriel", STRING_SQ_UNCLOSED);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("'gabriel", str);
}

TEST(token_to_str, Infile)
{
	token = token_create("gabriel", INFILE);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("<", str);
}

TEST(token_to_str, Infile_heredoc)
{
	token = token_create("gabriel", INFILE_HEREDOC);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("<<", str);
}

TEST(token_to_str, Outfile)
{
	token = token_create("gabriel", OUTFILE);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING(">", str);
}

TEST(token_to_str, Outfile_append)
{
	token = token_create("gabriel", OUTFILE_APPEND);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING(">>", str);
}

TEST(token_to_str, Pipe)
{
	token = token_create("gabriel", PIPE);
	str = token_to_str(token);
	
	TEST_ASSERT_NOT_NULL(str);
	TEST_ASSERT_EQUAL_STRING("|", str);
}

TEST_GROUP_RUNNER(token_to_str) {
	RUN_TEST_CASE(token_to_str, Null_token);
	RUN_TEST_CASE(token_to_str, String_unquoted);
	RUN_TEST_CASE(token_to_str, String_double_quoted_closed);
	RUN_TEST_CASE(token_to_str, String_double_quoted_unclosed);
	RUN_TEST_CASE(token_to_str, String_single_quoted_closed);
	RUN_TEST_CASE(token_to_str, String_single_quoted_unclosed);
	RUN_TEST_CASE(token_to_str, Infile);
	RUN_TEST_CASE(token_to_str, Infile_heredoc);
	RUN_TEST_CASE(token_to_str, Outfile);
	RUN_TEST_CASE(token_to_str, Outfile_append);
	RUN_TEST_CASE(token_to_str, Pipe);
}