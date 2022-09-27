/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:25:05 by acesar-l          #+#    #+#             */
/*   Updated: 2022/09/27 22:50:37 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_prompt_valid(char *prompt)
{
	if (ft_strnstr(prompt, "exit", ft_strlen(prompt)))
		return (false);
	return (true);
}
