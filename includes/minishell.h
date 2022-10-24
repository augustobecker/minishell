/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:17:28 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/20 15:10:45 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "defines.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

void		prompt(void);
t_bool		is_prompt_valid(char *prompt);
char		*current_path(void);
int			pwd(int fd_out);
int			cd(char *directory);
t_bool		is_syntax_valid(char *expression);
t_bool		there_is_a_valid_char(char *str, char *limiter);
t_bool		is_a_limiter(char c);
t_bool    	are_the_quotation_marks_closed(char *expression);
int	      	error(char *message, int exit_code);
void	indentify_args(char *prompt);

#endif
