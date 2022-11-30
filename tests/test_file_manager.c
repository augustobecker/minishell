/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:49:44 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/29 16:44:46 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"
#include "minishell.h"

void print_fd(t_file *file)
{
	printf("\n[PATH]\t== %s\n[ FD ]\t== %d\n[TYPE]\t== %d\n", file->path, file->fd, file->type);
}

// TEST_GROUP(file_manager);
// static t_file *file_1, *file_2, *file_3, *file_4;

// TEST_SETUP(file_manager) {
// 	file_1 = NULL;
// 	file_2 = file_create("files/minihell", 6, COMMON_FILE_IN);
// 	file_3 = file_create("files/file_3", 23, APPEND_FILE);
// 	file_4 = file_create("asdklasdsa", 27, HEREDOC_FILE);
// }
// // REFAZER OS TESTS COM O ASSERT STRING
// // VERIFICAR A CRIAÇÃO DOS ARQUIVOS
// TEST_TEAR_DOWN(file_manager) {
// 	file_destroy(&file_1);
// 	file_destroy(&file_2);
// 	file_destroy(&file_3);
// 	file_destroy(&file_4);
// }

// TEST(file_manager, NullFile)
// {
// 	file_manager(file_1);
// 	TEST_ASSERT_NULL(file_1);
// }

// TEST(file_manager, CommonFile)
// {
// 	file_manager(file_2);
// 	TEST_ASSERT_NOT_EQUAL_INT(-1, file_2->fd);
// }

// TEST(file_manager, AppendFile)
// {
// 	file_manager(file_3);
// 	TEST_ASSERT_NOT_EQUAL_INT(-1, file_3->fd);
// }

// TEST(file_manager, HereDoc)
// {
// 	file_manager(file_4);
// 	TEST_ASSERT_NOT_EQUAL_INT(-1, file_4->fd);
// }

// TEST_GROUP_RUNNER(file_manager)
// {
// 	RUN_TEST_CASE(file_manager, NullFile);
// 	RUN_TEST_CASE(file_manager, CommonFile);
// 	RUN_TEST_CASE(file_manager, AppendFile);
// 	RUN_TEST_CASE(file_manager, HereDoc);
// }
