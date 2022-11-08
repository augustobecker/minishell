/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:29:23 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/08 01:27:59 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(parse_pipe);

TEST_SETUP(parse_pipe) {}
TEST_TEAR_DOWN(parse_pipe) {}


TEST(parse_pipe, Null_params) {
	TEST_ASSERT_NULL(parse_pipe(NULL));
}

TEST(parse_pipe, Random_commands) {
	char *value;

	value = parse_pipe("ls |");
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ls &", value);
	free(value);

	value = parse_pipe("ls | wc -l");
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ls & wc -l", value);
	free(value);

	value = parse_pipe("ls | wc -l | > outfile");
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ls & wc -l & > outfile", value);
	free(value);

	value = parse_pipe("ls | wc -l | echo \"Hello|World|In|C|\"");
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ls & wc -l & echo \"Hello|World|In|C|\"", value);
	free(value);

	value = parse_pipe("ls | wc -l | echo \"Hello|World|In|C|\"| wc -l");
	TEST_ASSERT_NOT_NULL(value);
	TEST_ASSERT_EQUAL_STRING("ls & wc -l & echo \"Hello|World|In|C|\"& wc -l", value);
	free(value);
}

TEST_GROUP_RUNNER(parse_pipe) {
	RUN_TEST_CASE(parse_pipe, Null_params);
	RUN_TEST_CASE(parse_pipe, Random_commands);
}