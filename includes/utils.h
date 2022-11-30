/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:11:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/12 10:38:45 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "types.h"

size_t	array_size(char *const *array);
void	array_destroy(char **array);
char	**array_dup(char *const *array);
void	array_print(char *const *array);
void	array_append(char ***array, char *value);
t_bool	ft_strcmp(const char *str1, const char *str2);

#endif