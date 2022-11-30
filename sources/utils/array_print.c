/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:19:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 18:11:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	array_print(char *const *array)
{
	while (array && *array)
	{
		ft_printf("%s\n", *array);
		array++;
	}
}
