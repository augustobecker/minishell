/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:03 by acesar-l          #+#    #+#             */
/*   Updated: 2022/11/04 21:51:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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
	char	*outfile;
	int		*exit_code;
}	t_command;

#endif
