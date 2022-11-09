/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:40:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/09 08:25:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*file_create(const char *path, int fd, t_ftype type)
{
	t_file	*file;

	file = (t_file *) malloc(sizeof(t_file));
	if (file)
	{
		file->path = ft_strdup(path);
		file->fd = fd;
		file->type = type;
	}
	return (file);
}
