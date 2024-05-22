/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:00:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 10:51:02 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_list	*envp;

	if (ac != 1)
	{
		printf("Error!\nPlease execute the program without arguments!\n");
		return (1);
	}
	envp = env_parse(env);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
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
	return (0);
}







/*  !! TO FREE ENVP !!!!

	t_list	*test2;
	test2 = envp;
	while (envp)
	{
		printf("%s\n", envp->s);
		envp = envp->next;
	}
	envp = NULL;
	while (test2)
	{
		envp = test2;
		free(test2->s);
		test2 = test2->next;
		free(envp);
	}
*/