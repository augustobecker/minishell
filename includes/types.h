/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:03 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/08 17:54:11 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define FALSE 0
# define TRUE 1

typedef struct s_data
{
	char	**env;
	int	last_exit_code;

}	t_data;

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}	t_stack;

typedef enum e_ftype {
	COMMON,
	APPEND,
	HEREDOC
}	t_ftype;

typedef struct s_file {
	char *path;
	int	fd;
	t_ftype type;
}	t_file;

typedef struct s_command
{
	char	*command;
	char	**args;
	t_file	*infile;
	t_file	*outfile;
}	t_command;


#endif
