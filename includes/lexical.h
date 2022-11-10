/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:09:54 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/10 06:11:33 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef LEXICAL_H
# define LEXICAL_H

typedef enum e_tokentype
{
	STRING_SQ_CLOSED,
	STRING_SQ_UNCLOSED,
	STRING_DQ_CLOSED,
	STRING_DQ_UNCLOSED,
	STRING_UNQUOTED,
	INFILE,
	INFILE_HEREDOC,
	OUTFILE,
	OUTFILE_APPEND,
	PIPE
}	t_tokentype;

typedef struct s_token
{
	char		*value;
	t_tokentype type;
}	t_token;

t_token *token_create(char *value, t_tokentype type);
void	token_destroy(t_token *token);
t_token	*get_next_token(char **str);

#endif