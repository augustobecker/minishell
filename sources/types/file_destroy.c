/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:48:04 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/09 08:24:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	file_destroy(t_file **file)
{
	if (!file || !*file)
		return ;
	free((*file)->path);
	free(*file);
	*file = NULL;
}
