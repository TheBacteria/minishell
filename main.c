/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:00:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/08/17 18:05:19 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*s;
	t_list	*envp;
	t_token	*linked;
	int		key;

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
		if (linked == NULL)
			continue ;
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
