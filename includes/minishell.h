/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:17:28 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/20 12:57:01 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "types.h"
# include "utils.h"
# include "defines.h"
# include "lexical.h"
# include <limits.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

void	prompt(t_data *data);
t_bool	is_prompt_valid(char *prompt);
char	*current_path(void);
t_bool	is_syntax_valid(char *expression);
t_bool	there_is_a_valid_char(char *str, char *limiter);
t_bool	is_a_limiter(char c);
t_bool	are_the_quotation_marks_closed(char *expression);
int		error(char *message, int exit_code);
char	*tokenization(char *prompt);
char	*get_env_value(const char *name, char *const *envp);
char	**parse_pipe(char *prompt);
char	*expand_vars(const char *prompt, char *const *envp);
void	handle_signal(void);
char	*command_creator(char *prompt);
t_list	*cmd_create_list(char *const *cmds);
void	handle_signal(void);
char	*get_var_name(const char *string);
char	*get_var_value(const char *string);
char	**to_unset(char **envp, char *var_name);
void	file_manager(t_data *data, t_file	*file);
char  **set_env_value(char *name, char *value, char **envp);

// Builtins
void execute_builtin(t_cmd *command, char *const *envp);
t_bool	is_a_builtin(char *command);
int		echo(char **arguments);
int     pwd(void);
int	    cd(char *directory, int argc, char *const *env);

//execution
void	init_files(t_data *data, t_list *list);
void	command_not_found(char *command);
char    **get_cmd_paths(char *const *envp);
void    execution_process(t_data *data, t_list *list);
void    execute_single_cmd(t_data *data, t_cmd *command, int fd_pipe_in);
int     execute_cmd_to_pipe(t_data *data, t_cmd *command, int fd_pipe_in);
int     execute(t_cmd *command, char *const *envp);


#endif
