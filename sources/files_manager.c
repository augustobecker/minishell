/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:15:15 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/11/17 11:20:10 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_manager(t_file	*file)
{
	if (file == NULL)
		return ;
	if (file->type == COMMON_FILE)
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file->type == APPEND_FILE)
		file->fd = open(file->path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file->type == HEREDOC_FILE)
		file->fd = open("/tmp/herecdoc_minihell", O_WRONLY | O_CREAT | \
				O_APPEND, 0644);
}
