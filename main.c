/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:00:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/01 10:43:05 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_list	*envp;
	t_token	*linked;

	if (ac != 1)
	{
		printf("Error!\nPlease execute the program without arguments!\n");
		return (1);
	}
	envp = env_parse(env);
	while (1)
	{
		s = readline("minishell:");
		if (!s)
		{
			printf("Error!\nreadline returned NULL\n");
			return (1);
		}
		linked = mz_parser(s);
		free(s);

		int i = 0;
		while (linked)
		{
			printf("%s  --> %i\n", linked->cmd, linked->nature);
			while (linked->args && linked->args[i])
			{
				printf("\n arg_%i ->>>>> %s\n", i, linked->args[i]);
				i++;
			}
			linked = linked->next;
		}
	}
	return (0);
}





// ls -la | ( cat -e && wc -l && echo '$VAR') | grep "something i want" > outfile || < infile cat

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