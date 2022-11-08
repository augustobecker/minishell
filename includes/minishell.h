/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:17:28 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/08 11:12:57 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "defines.h"
# include <limits.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

void	prompt(void);
t_bool	is_prompt_valid(char *prompt);
char	*current_path(void);
t_bool	is_syntax_valid(char *expression);
t_bool	there_is_a_valid_char(char *str, char *limiter);
t_bool	is_a_limiter(char c);
t_bool	are_the_quotation_marks_closed(char *expression);
int		error(char *message, int exit_code);
void	clear_stack(t_stack **stack);
t_stack	*stack_new(char c);
void	stack_push(t_stack **stack, t_stack *new);
void	stack_pop(t_stack **stack);
char	*tokenization(char *prompt);
char	*get_env_value(const char *name, char *const *envp);
char	*parse_pipe(char *prompt);
char	*expand_vars(const char *prompt, char *const *envp);
void	handle_signal(void);
char	*command_creator(char *prompt);
t_command	*command_create(void);
void		command_destroy(t_command **cmd);
t_command 	*command_parse_str(const char *str);

// Utils
size_t		array_size(char *const *array);
void		array_destroy(char **array);

// Builtins
int			echo(char **arguments);
int			pwd(int fd_out);
int			cd(char *directory);

#endif
