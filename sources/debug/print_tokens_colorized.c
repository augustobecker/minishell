/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens_colorized.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:54:31 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/15 10:52:18 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"

void	print_tokens_colorized(const char *str)
{
	char	*prompt;
	t_token	*token;
	char	*token_str;

	if (!str)
		return ;
		
	prompt = (char *) str;
	token = get_next_token(&prompt);
	
	while (token)
	{
		token_str = token_to_str(token);

		// Verde -- Infile / Heredoc
		if (token->type == INFILE || token->type == INFILE_HEREDOC)
			printf("\033[92m%s \033[00m", token_str);

		// Amarelo -- Outfile - replace/append
		if (token->type == OUTFILE || token->type == OUTFILE_APPEND)
			printf("\033[33m%s \033[00m", token_str);
		
		// Branco -- String unquoted
		if (token->type == STRING_UNQUOTED)
			printf("\033[39m%s \033[00m", token_str);
			
		// Azul -- String double quoted
		if (token->type == STRING_DQ_CLOSED || token->type == STRING_DQ_UNCLOSED)
			printf("\033[34m%s \033[00m", token_str);
			
		// Cyan -- String single quoted
		if (token->type == STRING_SQ_CLOSED || token->type == STRING_SQ_UNCLOSED)
			printf("\033[36m%s \033[00m", token_str);

		// Vermelho -- Pipe
		if (token->type == PIPE)
			printf("\033[31m%s \033[00m", token_str);
			
		free(token_str);
		token_destroy(token);
		token = get_next_token(&prompt);
	}
	
	token_destroy(token);
	printf("\n");
}