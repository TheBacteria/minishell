/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:56 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/27 18:46:53 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*mz_nuller(t_token *head)
{
	int		i;
	int		flag;
	char	*arr;

	i = 0;
	arr = head->args[0];
	flag = -1;
	while (arr[i])
	{
		if (flag == -1 && arr[i] == '\"')
			flag = 1;
		else if (flag == -1 && arr[i] == '\'')
			flag = 2;
		else
		{
			if (flag == -1 && arr[i] == 32)
				arr[i] = '\0';
			else if ((flag == 1 && arr[i] == '\"') || (flag == 2 && arr[i] == '\''))
				flag = -1;
		}
			i++;
		}
		return (arr);
}

void mz_splitter(t_token *head)
{
	t_token	*tmp;
	int		len;
	int		i;

	tmp = head;
	while (tmp)
	{
		if (tmp->args)
		{
			i = 1;
			len = ft_strlen(tmp->args[0]);
			tmp->args[0] = mz_nuller(tmp);
			tmp->args = mz_nul_split(tmp->args[0], '\0', len);
		}
		tmp = tmp->next;
	}
}
// ls -l -p > haha -a -z || echo hello as das ""