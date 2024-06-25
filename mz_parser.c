/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:54:01 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/25 17:09:08 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void mz_splitter(t_token *head)
{
	t_token	*tmp;

	tmp = head;
	while (head && head->args)
	{
		head->args = mz_split(head->args[0], ' ');
		head = head->next;
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
