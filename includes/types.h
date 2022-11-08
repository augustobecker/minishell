/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:03 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/08 09:01:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define FALSE 0
# define TRUE 1

typedef struct s_data
{
	int	last_exit_code;

}	t_data;

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}	t_stack;

typedef struct s_command
{
	char	*command;
	char	**args;
	char	*infile;
	t_bool	is_heredoc;
	char	*outfile;
	t_bool	is_append;
	int		*exit_code;
}	t_command;

#endif
