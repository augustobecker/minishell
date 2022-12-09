/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:53:19 by gasouza           #+#    #+#             */
/*   Updated: 2022/12/09 14:11:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "minishell.h"

typedef struct s_syntax
{
	t_token	*current_token;
	t_token	*last_token;
	t_token	*next_token;
	char	**error;
}	t_syntax;

void	syntax_init(t_syntax *syntax, char **error);
void	syntax_clear(t_syntax *syntax);
t_bool	syntax_checker(char *str, char **error);

#endif