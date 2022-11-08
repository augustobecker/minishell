/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commmand_parse_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:44:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/08 09:49:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(command_parse_str);

TEST_SETUP(command_parse_str) {}
TEST_TEAR_DOWN(command_parse_str) {}

static void asstert_in_out(char *prompt, char *infile, char *outfile)
{	
	t_command *cmd;

	cmd = command_parse_str(prompt);
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING(infile, cmd->infile);
	TEST_ASSERT_EQUAL_STRING(outfile, cmd->outfile);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
}

static void asstert_in_out_args(char *prompt, char *infile, char *outfile)
{	
	t_command *cmd;

	cmd = command_parse_str(prompt);
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING(infile, cmd->infile);
	TEST_ASSERT_EQUAL_STRING(outfile, cmd->outfile);
	TEST_ASSERT_EQUAL_INT(3, array_size(cmd->args));
	TEST_ASSERT_EQUAL_STRING("-l", cmd->args[0]);
	TEST_ASSERT_EQUAL_STRING("-a", cmd->args[1]);
	TEST_ASSERT_EQUAL_STRING("-e", cmd->args[2]);
	TEST_ASSERT_EQUAL_INT(0, cmd->exit_code);
	command_destroy(&cmd);
}

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
	asstert_in_out("ls", NULL, NULL);
	asstert_in_out(" ls", NULL, NULL);
	asstert_in_out(" ls  ", NULL, NULL);
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

	asstert_in_out_args(" ls  -l -a -e", NULL, NULL);

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

TEST(command_parse_str, With_infile_and_outfile)
{
	asstert_in_out("< infile ls >   outfile", "infile", "outfile");
	asstert_in_out(">   outfile ls < infile", "infile", "outfile");
	asstert_in_out("< infile > outfile ls  ", "infile", "outfile");
	asstert_in_out("> outfile < infile ls    ", "infile", "outfile");
	asstert_in_out("ls >    outfile < infile", "infile", "outfile");
	asstert_in_out("  ls < infile > outfile   ", "infile", "outfile");

	asstert_in_out_args("< infile ls -l -a -e >   outfile", "infile", "outfile");
	asstert_in_out_args(">   outfile ls -l -a -e < infile", "infile", "outfile");
	asstert_in_out_args("< infile > outfile ls -l -a -e  ", "infile", "outfile");
	asstert_in_out_args("> outfile < infile ls -l -a -e   ", "infile", "outfile");
	asstert_in_out_args("ls -l -a -e >    outfile < infile", "infile", "outfile");
	asstert_in_out_args("  ls  -l -a -e < infile > outfile   ", "infile", "outfile");
}

TEST(command_parse_str, With_multi_infiles)
{
	asstert_in_out("< infile1 < infile2 ls", "infile2", NULL);
	asstert_in_out("< infile1 < infile2 < infile3 ls", "infile3", NULL);
	asstert_in_out(" < infile1 ls < infile2", "infile2", NULL);
	asstert_in_out("ls < infile1 < infile2 ", "infile2", NULL);
	asstert_in_out("ls < infile1 < infile2 < infile3 ", "infile3", NULL);
	
	asstert_in_out_args("< infile1 < infile2 ls -l -a -e", "infile2", NULL);
	asstert_in_out_args("< infile1 ls -l -a -e  < infile2", "infile2", NULL);
	asstert_in_out_args("ls -l -a -e < infile1  < infile2", "infile2", NULL);
}

TEST(command_parse_str, With_multi_outfiles)
{
	asstert_in_out("> outfile1 > outfile2 ls", NULL, "outfile2");
	asstert_in_out(" > outfile1 ls > outfile2", NULL, "outfile2");
	asstert_in_out("ls > outfile1 > outfile2 ", NULL, "outfile2");
	
	asstert_in_out_args("> outfile1 > outfile2 ls -l -a -e", NULL, "outfile2");
	asstert_in_out_args("> outfile1 ls -l -a -e  > outfile2", NULL, "outfile2");
	asstert_in_out_args("ls -l -a -e > outfile1  > outfile2", NULL, "outfile2");
}

TEST(command_parse_str, With_multi_in_and_out_files)
{
	asstert_in_out("> outfile1 > outfile2 ls < infile1 < infile2", "infile2", "outfile2");
	asstert_in_out("< infile1 > outfile1 ls > outfile2 < infile2", "infile2", "outfile2");
	asstert_in_out("ls > outfile1 < infile1 > outfile2 < infile2", "infile2", "outfile2");
	
	asstert_in_out_args("> outfile1 > outfile2 ls -l -a -e < infile1 < infile2", "infile2", "outfile2");
	asstert_in_out_args("> outfile1 < infile1 ls -l -a -e  > outfile2 < infile2", "infile2", "outfile2");
	asstert_in_out_args("ls -l -a -e < infile1 > outfile1 < infile2 > outfile2", "infile2", "outfile2");
}

TEST(command_parse_str, With_outfile_append)
{
	t_command *cmd;

	cmd = command_parse_str("ls >> outfile");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_append);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);

	cmd = command_parse_str(" >> outfile ls ");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile", cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_append);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);

	cmd = command_parse_str(" >> outfile1 ls >> outfile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile2", cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_append);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);

	cmd = command_parse_str(" > outfile1 ls >> outfile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile2", cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_append);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
	
	cmd = command_parse_str(" >> outfile1 ls > outfile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_NULL(cmd->infile);
	TEST_ASSERT_EQUAL_STRING("outfile2", cmd->outfile);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
}

TEST(command_parse_str, With_infile_heredoc)
{
	t_command *cmd;

	cmd = command_parse_str("ls << infile");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_heredoc);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);

	cmd = command_parse_str(" << infile ls");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_heredoc);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
	
	cmd = command_parse_str(" << infile1 ls  << infile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile2", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_heredoc);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
	
	cmd = command_parse_str(" < infile1 ls  << infile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile2", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_TRUE(cmd->is_heredoc);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
	
	cmd = command_parse_str(" << infile1 ls < infile2");
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING("ls", cmd->command);
	TEST_ASSERT_EQUAL_STRING("infile2", cmd->infile);
	TEST_ASSERT_NULL(cmd->outfile);
	TEST_ASSERT_FALSE(cmd->is_heredoc);
	TEST_ASSERT_FALSE(cmd->is_append);
	TEST_ASSERT_NULL(cmd->args);
	command_destroy(&cmd);
}


// Testar sem informar o commando, somente infile / outfile
// Outfile Append
// Infile << heredoc
// infile e outfile sem espaço antes <infile >outfile

TEST_GROUP_RUNNER(command_parse_str)
{
	RUN_TEST_CASE(command_parse_str, Null_str);
	RUN_TEST_CASE(command_parse_str, Empty_string);
	RUN_TEST_CASE(command_parse_str, Without_args);
	RUN_TEST_CASE(command_parse_str, With_args);
	RUN_TEST_CASE(command_parse_str, With_infile);
	RUN_TEST_CASE(command_parse_str, With_outfile);
	RUN_TEST_CASE(command_parse_str, With_infile_and_outfile);
	RUN_TEST_CASE(command_parse_str, With_multi_infiles);
	RUN_TEST_CASE(command_parse_str, With_multi_outfiles);
	RUN_TEST_CASE(command_parse_str, With_multi_in_and_out_files);
	RUN_TEST_CASE(command_parse_str, With_outfile_append);
	RUN_TEST_CASE(command_parse_str, With_infile_heredoc);
}