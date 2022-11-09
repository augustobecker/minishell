/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_commmand_parse_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:44:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/09 07:22:36 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

TEST_GROUP(command_parse_str);

TEST_SETUP(command_parse_str) {}
TEST_TEAR_DOWN(command_parse_str) {}

static void assert_cmd(const char *prompt, t_cmd *cmp)
{
	t_cmd *cmd;

	cmd = cmd_parse_str(prompt);
	TEST_ASSERT_NOT_NULL(cmd);
	TEST_ASSERT_EQUAL_STRING(cmp->command, cmd->command);
	if (cmp->infile)
	{
		TEST_ASSERT_NOT_NULL(cmd->infile);
		TEST_ASSERT_EQUAL_STRING(cmp->infile->path, cmd->infile->path);
		TEST_ASSERT_EQUAL_INT(cmp->infile->fd, cmd->infile->fd);
		TEST_ASSERT_EQUAL_INT(cmp->infile->type, cmd->infile->type);
	}
	else
	{
		TEST_ASSERT_NULL(cmd->infile);
	}
	if (cmp->outfile)
	{
		TEST_ASSERT_NOT_NULL(cmd->outfile);
		TEST_ASSERT_EQUAL_STRING(cmp->outfile->path, cmd->outfile->path);
		TEST_ASSERT_EQUAL_INT(cmp->outfile->fd, cmd->outfile->fd);
		TEST_ASSERT_EQUAL_INT(cmp->outfile->type, cmd->outfile->type);
	}
	else
	{
		TEST_ASSERT_NULL(cmd->outfile);
	}
	if (cmp->args)
	{
		TEST_ASSERT_EQUAL_INT(array_size(cmp->args), array_size(cmd->args));
		size_t i = 0;
		while (cmp->args[i])
		{
			TEST_ASSERT_EQUAL_STRING(cmp->args[i], cmd->args[i]);
			i++;
		}
	}
	else
	{	
		TEST_ASSERT_NULL(cmd->args);
	}
	cmd_destroy(&cmd);
}

TEST(command_parse_str, Null_str)
{
	TEST_ASSERT_NULL(cmd_parse_str(NULL));
}

TEST(command_parse_str, Empty_string)
{
	TEST_ASSERT_NULL(cmd_parse_str(""));
}

TEST(command_parse_str, Without_command)
{
	t_file *infile = file_create("infile", 0, COMMON_FILE);
	t_file *outfile = file_create("outfile", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("", NULL, infile, outfile);
	
	assert_cmd("< infile > outfile", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, Without_args)
{
	t_cmd *cmd = cmd_create("ls", NULL, NULL, NULL);
	
	assert_cmd("ls", cmd);
	assert_cmd(" ls ", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_args)
{
	char *args[] = {"-l", "-a", "-e", NULL};
	t_cmd *cmd = cmd_create("ls", args, NULL, NULL);

	assert_cmd("ls -l -a -e", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_string_args)
{
	char *args[] = {" string args ", NULL};
	t_cmd *cmd = cmd_create("echo", args, NULL, NULL);

	assert_cmd(" echo \" string args \"  ", cmd);
	assert_cmd(" echo \"\"\" string args \"\"\"  ", cmd);
	assert_cmd(" echo ' string args '  ", cmd);
	assert_cmd(" echo ''' string args '''  ", cmd);

	char *args2[] = {" ' string args ' ", NULL};
	array_destroy(cmd->args);
	cmd->args = array_dup(args2);

	assert_cmd(" echo \"' string args '\"  ", cmd);
	
	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_infile)
{
	t_file *infile = file_create("infile", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, infile, NULL);

	assert_cmd("< infile ls", cmd);
	assert_cmd(" ls < infile", cmd);

	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd("< infile ls -l -a -e", cmd);
	assert_cmd(" ls -l  -a  -e < infile ", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_outfile)
{
	t_file *outfile = file_create("outfile", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, NULL, outfile);

	assert_cmd(" ls > outfile", cmd);
	assert_cmd("> outfile ls", cmd);

	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd(" ls -l  -a  -e > outfile ", cmd);
	assert_cmd("> outfile ls -l -a -e", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_infile_and_outfile)
{
	t_file *infile = file_create("infile", 0, COMMON_FILE);
	t_file *outfile = file_create("outfile", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, infile, outfile);
	
	assert_cmd("< infile ls >   outfile", cmd);
	assert_cmd(">   outfile ls < infile", cmd);
	assert_cmd("< infile > outfile ls  ", cmd);
	assert_cmd("> outfile < infile ls    ", cmd);
	assert_cmd("ls >    outfile < infile", cmd);
	assert_cmd("  ls < infile > outfile   ", cmd);

	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd("< infile ls -l -a -e >   outfile", cmd);
	assert_cmd(">   outfile ls -l -a -e < infile", cmd);
	assert_cmd("< infile > outfile ls -l -a -e  ", cmd);
	assert_cmd("> outfile < infile ls -l -a -e   ", cmd);
	assert_cmd("ls -l -a -e >    outfile < infile", cmd);
	assert_cmd("  ls  -l -a -e < infile > outfile   ", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_multi_infiles)
{
	t_file *infile = file_create("infile2", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, infile, NULL);

	assert_cmd("< infile1 < infile2 ls", cmd);
	assert_cmd(" < infile1 ls < infile2", cmd);
	assert_cmd("ls < infile1 < infile2 ", cmd);
	
	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd("< infile1 < infile2 ls -l -a -e", cmd);
	assert_cmd("< infile1 ls -l -a -e  < infile2", cmd);
	assert_cmd("ls -l -a -e < infile1  < infile2", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_multi_outfiles)
{
	t_file *outfile = file_create("outfile2", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, NULL, outfile);
	
	assert_cmd("> outfile1 > outfile2 ls", cmd);
	assert_cmd(" > outfile1 ls > outfile2", cmd);
	assert_cmd("ls > outfile1 > outfile2 ", cmd);
	assert_cmd("ls >> outfile1 > outfile2 ", cmd);
	
	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd("> outfile1 > outfile2 ls -l -a -e", cmd);
	assert_cmd("> outfile1 ls -l -a -e  > outfile2", cmd);
	assert_cmd("ls -l -a -e > outfile1  > outfile2", cmd);
	assert_cmd(">> outfile1 ls -l -a -e  > outfile2", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_multi_in_and_out_files)
{
	t_file *infile = file_create("infile2", 0, COMMON_FILE);
	t_file *outfile = file_create("outfile2", 0, COMMON_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, infile, outfile);
	
	assert_cmd("> outfile1 > outfile2 ls < infile1 < infile2", cmd);
	assert_cmd("< infile1 > outfile1 ls > outfile2 < infile2", cmd);
	assert_cmd("ls > outfile1 < infile1 > outfile2 < infile2", cmd);
	
	cmd->args = ft_split("-l -a -e", ' ');
	assert_cmd("> outfile1 > outfile2 ls -l -a -e < infile1 < infile2", cmd);
	assert_cmd("> outfile1 < infile1 ls -l -a -e  > outfile2 < infile2", cmd);
	assert_cmd("ls -l -a -e < infile1 > outfile1 < infile2 > outfile2", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_outfile_append)
{
	t_file *outfile = file_create("outfile", 0, APPEND_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, NULL, outfile);

	assert_cmd("ls >> outfile", cmd);
	assert_cmd(" >> outfile ls ", cmd);
	assert_cmd(" >> outfile_ ls >> outfile", cmd);
	assert_cmd(" > outfile_ ls >> outfile", cmd);

	cmd_destroy(&cmd);
}

TEST(command_parse_str, With_infile_heredoc)
{
	t_file *infile = file_create("heredoc", 0, HEREDOC_FILE);
	t_cmd *cmd = cmd_create("ls", NULL, infile, NULL);
	
	assert_cmd("ls << heredoc", cmd);
	assert_cmd(" << heredoc ls", cmd);
	assert_cmd("<< heredoc__ ls  << heredoc", cmd);
	assert_cmd("< infile ls  << heredoc", cmd);

	cmd_destroy(&cmd);
}

// TODO Parametros entre aspas e com espaços

TEST_GROUP_RUNNER(command_parse_str)
{
	RUN_TEST_CASE(command_parse_str, Null_str);
	RUN_TEST_CASE(command_parse_str, Empty_string);
	RUN_TEST_CASE(command_parse_str, Without_command);
	RUN_TEST_CASE(command_parse_str, Without_args);
	RUN_TEST_CASE(command_parse_str, With_args);
	RUN_TEST_CASE(command_parse_str, With_string_args);
	RUN_TEST_CASE(command_parse_str, With_infile);
	RUN_TEST_CASE(command_parse_str, With_outfile);
	RUN_TEST_CASE(command_parse_str, With_infile_and_outfile);
	RUN_TEST_CASE(command_parse_str, With_multi_infiles);
	RUN_TEST_CASE(command_parse_str, With_multi_outfiles);
	RUN_TEST_CASE(command_parse_str, With_multi_in_and_out_files);
	RUN_TEST_CASE(command_parse_str, With_outfile_append);
	RUN_TEST_CASE(command_parse_str, With_infile_heredoc);
}