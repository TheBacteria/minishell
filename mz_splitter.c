/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:56 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/28 15:33:56 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*mz_nuller(t_token *head, int n)
{
	int		i;
	int		flag;
	char	*arr;

	i = 0;
	arr = head->args[n];
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

static char ***mz_triple_init(t_token *head)
{
	t_token *tmp;
	int		i;
	char	***final;

	i = 0;
	final = NULL;
	tmp = head;
	if (!head)
		return (NULL);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	final = (char ***)malloc(i * sizeof(char **) + 1);
	if (!final)
	{
		printf("malloc fail in triple arr\n");
		exit(1);
	}
	while (i > 0)
	{
		final[i] = NULL;
		i--;
	}
	// final[i] = '\0';
	return (final);
}

void mz_splitter(t_token *head)
{
	t_token	*tmp;
	int		len;
	int		i;
	char	***arr;
	int		j;

	tmp = head;
	arr = mz_triple_init(head);
	j= 0;
	while (tmp)
	{
		i = 0;
		while (tmp && tmp->args && tmp->args[i])
		{
			len = ft_strlen(tmp->args[i]);
			tmp->args[i] = mz_nuller(tmp, i);
			// if (!arr[j])
			// 	arr[j] = mz_nul_split(tmp->args[i], '\0', len);
			// else
			arr[j] = mz_arr(arr[j], mz_nul_split(tmp->args[i], '\0', len), NULL, 2);
			
			printf("\n======%s\n========%i-->%i\n", tmp->args[0], 0, i);
			printf("\n======%s\n========%i-->%i\n", tmp->args[1], 1, i);

			i++;
		}
		tmp->args = arr[j];
		tmp = tmp->next;
		j++;
	}
}
// ls -l -p > haha -a -z || echo hello as das ""