/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:42:13 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/12/05 09:56:13 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_history(void)
{
	HISTORY_STATE	*myhist;
	HIST_ENTRY		**mylist;
	int				i;

	i = 0;
	myhist = history_get_history_state ();
	mylist = history_list ();
	while (i < myhist->length)
	{
		free_history_entry (mylist[i]);
		i++;
	}
	free (myhist);
	free (mylist);
}
