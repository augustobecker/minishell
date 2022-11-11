/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:09:54 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/11 09:19:52 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_H
# define LEXICAL_H
# include "minishell.h"

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
	t_tokentype	type;
}	t_token;

t_token	*token_create(char *value, t_tokentype type);
void	token_destroy(t_token *token);
t_token	*get_next_token(char **str);
t_token	*get_string_double_quotes_token(char *start, char **str);
t_token	*get_string_single_quotes_token(char *start, char **str);
t_token	*get_string_unquoted_token(char *start, char **str);
t_token	*get_infile_token(char *start, char **str);
t_token	*get_outfile_token(char *start, char **str);

#endif