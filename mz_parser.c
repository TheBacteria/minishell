/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:54:01 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/26 12:47:42 by mzouine          ###   ########.fr       */
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

static void mz_splitter(t_token *head)
{
	t_token	*tmp;
	int		len;

	tmp = head;
	if (tmp && tmp->args)
	{
		len = ft_strlen(tmp->args[0]);
		tmp->args[0] = mz_nuller(tmp);
		tmp->args = mz_nul_split(tmp->args[0], '\0', len);
	}
}

static t_list *mz_first_scan(char *s)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (s[i])
	{
		if (s[i] == 32 && s[i+1] == '\0')
			return (head);
		if (mz_is_space(s[i]))
			i = make_space_nd(&head, s, i);
		else if (mz_is_special(s[i]))
			i = make_special_nd(&head, s, i);
		else
			i = make_word_nd(&head, s, i);
	}
	return (head);
}

t_token	*mz_parser(char *s)
{
	t_list	*head;
	t_list	*tmp;
	t_token	*list;
	
	head = mz_first_scan(s);
	
	tmp = head;
	// mz_syntax(tmp);
	// here should be the second scan for syntax errors!
	list = mz_last_scan(head);
	mz_splitter(list);
	return (list);
}
