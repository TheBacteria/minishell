/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:05:47 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/23 12:05:03 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*env_parse(char **envp)
{
	int		i;
	int		j;
	t_list	*env;
	t_list	*head;
	
	i = 0;
	head = NULL;
	while (envp[i])
	{
		env = mz_lstnew(envp[i]);
		mz_lstadd_back(&head, env);
		i++;
	}
	return (head);
}
