/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:00:03 by acesar-l          #+#    #+#             */
/*   Updated: 2022/10/31 14:43:23 by gnuncio-         ###   ########.fr       */
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
	char c;
	struct s_stack *next;
}	t_stack;

typedef struct s_command
{
	char	*command;
	char	**command_argument;
	char	*infile;
	char	*outfile;
	int		*exit_code;
	struct	s_command *next;
} t_command;


#endif
