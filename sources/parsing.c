/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:47:45 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/10/20 15:44:44 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// arquivo de entrada
// arquivo de saida
// comando

// ls | wc -c

//cmd | cmd < infile | cmd > outfile

// < infile
// cmd < infile (Last)

// cmd | cmd | cmd ...

// > outfile (last)
// >> outfile (last)

//>>> entrada: infile > cmd | cmd > outfile

int	find_limiter(char *prompt)
{
	int	i;
	int	j;

	i = 0;
	while (prompt[i])
	{
		if (is_a_limiter(prompt[i] == true))  ///((c == '<') || (c == '>') || (c == '|') || (c == '&'))
			return (i);
		i++;
	}
	return ('\0');
}

void	indentify_args(char *prompt)
{
	//printf("%s\n", prompt);
}

/* // comando
cmd <
| cmd |
| cmd >
cmd |
| cmd
cmd >
cmd <
*/

/* infile
< infile
< infile |
< infile >   //válido e funciona
< infile
*/

// < arquivo-infile
// > arquivo-outfile