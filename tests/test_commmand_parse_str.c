/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commmand_parse_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:44:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/06 19:48:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(command_parse_str);

TEST_SETUP(command_parse_str) {}
TEST_TEAR_DOWN(command_parse_str) {}

TEST(command_parse_str, Null_str)
{
	TEST_ASSERT_NULL(command_parse_str(NULL));
}

TEST(command_parse_str, Empty_string)
{
	TEST_ASSERT_NULL(command_parse_str(""));
}

TEST(command_parse_str, Without_args)
{
	t_command *cmd;

	cmd = command_parse_str(" ls ");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_NULL(cmd->args);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	TEST_ASSERT_NOT_NULL(cmd->command);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	command_destroy(&cmd);

	cmd = command_parse_str("   ls   ");
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	command_destroy(&cmd);
}

TEST(command_parse_str, With_args)
{
	t_command *cmd;

	cmd = command_parse_str("ls -l");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_INT(1, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	command_destroy(&cmd);

	cmd = command_parse_str("ls -l -a -e");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_INT(3, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	TEST_ASSERT_EQUAL_STRING("-a", cmd->args[1]);
	TEST_ASSERT_EQUAL_STRING("-e", cmd->args[2]);
	command_destroy(&cmd);

	cmd = command_parse_str(" echo \"testando\"  ");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("echo", cmd->command);
	TEST_ASSERT_EQUAL_INT(1, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("\"testando\"", cmd->args[0]);
	command_destroy(&cmd);
}

TEST(command_parse_str, With_infile)
{
	t_command *cmd;

	cmd = command_parse_str("< infile ls");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_NULL(cmd->args);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);

	cmd = command_parse_str("< infile ls -l -a -e");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_EQUAL_INT(3, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	TEST_ASSERT_EQUAL_STRING("-a", cmd->args[1]);
	TEST_ASSERT_EQUAL_STRING("-e", cmd->args[2]);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);
}

TEST(command_parse_str, With_outfile)
{
	t_command *cmd;

	cmd = command_parse_str("> outfile ls");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_NULL(cmd->args);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);

	cmd = command_parse_str("> outfile ls -l -a -e");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_INT(3, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	TEST_ASSERT_EQUAL_STRING("-a", cmd->args[1]);
	TEST_ASSERT_EQUAL_STRING("-e", cmd->args[2]);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);
}

static void assert_infile_and_outfile(char *prompt)
{	t_command *cmd;

	cmd = command_parse_str(prompt);
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
}

static void assert_infile_and_outfile_args(char *prompt)
{	t_command *cmd;

	cmd = command_parse_str(prompt);
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_EQUAL_INT(3, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	TEST_ASSERT_EQUAL_STRING("-a", cmd->args[1]);
	TEST_ASSERT_EQUAL_STRING("-e", cmd->args[2]);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);
}

TEST(command_parse_str, With_infile_and_outfile)
{
	assert_infile_and_outfile("< infile ls >   outfile");
	assert_infile_and_outfile(">   outfile ls < infile");
	assert_infile_and_outfile("< infile > outfile ls  ");
	assert_infile_and_outfile("> outfile < infile ls    ");
	assert_infile_and_outfile("ls >    outfile < infile");
	assert_infile_and_outfile("  ls < infile > outfile   ");

	assert_infile_and_outfile_args("< infile ls -l -a -e >   outfile");
	assert_infile_and_outfile_args(">   outfile ls -l -a -e < infile");
	assert_infile_and_outfile_args("< infile > outfile ls -l -a -e  ");
	assert_infile_and_outfile_args("> outfile < infile ls -l -a -e   ");
	assert_infile_and_outfile_args("ls -l -a -e >    outfile < infile");
	assert_infile_and_outfile_args("  ls  -l -a -e < infile > outfile   ");
}


// Testar sem informar o commando, somente infile / outfile
// Outfile Append
// Infile << heredoc


TEST_GROUP_RUNNER(command_parse_str)
{
	RUN_TEST_CASE(command_parse_str, Null_str);
	RUN_TEST_CASE(command_parse_str, Empty_string);
	RUN_TEST_CASE(command_parse_str, Without_args);
	RUN_TEST_CASE(command_parse_str, With_args);
	RUN_TEST_CASE(command_parse_str, With_infile);
	RUN_TEST_CASE(command_parse_str, With_outfile);
	RUN_TEST_CASE(command_parse_str, With_infile_and_outfile);
}