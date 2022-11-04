/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllTests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:00:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/11/01 11:12:31 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity_fixture.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(get_env_value);
	RUN_TEST_GROUP(expand_vars);
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
