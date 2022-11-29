/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:03 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/29 23:23:27 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}	t_stack;

typedef enum e_ftype {
	COMMON_FILE_IN,
	COMMON_FILE_OUT,
	APPEND_FILE,
	HEREDOC_FILE
}	t_ftype;

typedef struct s_file {
	char	*path;
	int		fd;
	t_ftype	type;
}	t_file;

typedef struct s_cmd
{
	char	*command;
	char	**args;
	t_file	*infile;
	t_file	*outfile;
}	t_cmd;

typedef struct s_data
{
	char	*prompt_path;
	char	**env;
	int		last_exit_code;
	t_file	*empty_infile;
	t_file	*discarded_outfile;
}	t_data;

t_stack	*stack_new(char c);
void	stack_push(t_stack **stack, t_stack *new);
void	stack_pop(t_stack **stack);
void	clear_stack(t_stack **stack);

t_cmd	*cmd_create(const char *cmd, char *const *args, t_file *i, t_file *o);
void	cmd_destroy(t_cmd **cmd);
t_cmd	*cmd_parse_str(const char *str);
t_file	*file_create(const char *path, int fd, t_ftype type);
void	file_destroy(t_file **file);

#endif
