/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:00:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 10:42:03 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void appah()
{
	system("leaks minishell");
}

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_list	*test;
	t_list	*test2;

	if (ac != 1)
	{
		printf("Error!\nPlease execute the program without arguments!\n");
		return (1);
	}
	test = env_parse(env);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	test2 = test;
	while (test)
	{
		printf("%s\n", test->s);
		test = test->next;
	}
	test = NULL;
	while (test2)
	{
		test = test2;
		free(test2->s);
		test2 = test2->next;
		free(test);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (1)
	{
		s = readline("minishell:");
		if (!s)
		{
			printf("Error!\nreadline returned NULL\n");
			return (1);
		}
		mz_parser(s);
		free(s);
	}
	atexit(appah);
	return (0);
}
