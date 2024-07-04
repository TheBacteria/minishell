/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:00:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:36:00 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_list	*envp;
	t_token	*linked;
	int 	key;

	(void)av;
	if (ac != 1)
	{
		printf("Error!\nPlease execute the program without arguments!\n");
		return (1);
	}
	envp = env_parse(env);
	while (1)
	{
		s = readline("minishell:");
		add_history(s);
		if (!s)
		{
			printf("Error!\nreadline returned NULL\n");
			return (1);
		}
		key = mz_key_assign(&s);
		linked = mz_parser(s);
		free(s);

		int i = 0;
		printf("\nKey: %i\n", key);
		while (linked)
		{
			i = 0;
			printf("\n\n%s  --> %i\n", linked->cmd, linked->nature);
			while (linked->args && linked->args[i])
			{
				printf("arg_%i ->> [%s]\n", i, linked->args[i]);
				i++;
			}
			linked = linked->next;
		}
	}
	return (0);
}

// ma 7edek ma l9itich space kharja 3la quotes rak ba9i fel command
// ghadi t7iyed lquote li l9iti lewla o t7iyed li ghadi tl9a b7alha;



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