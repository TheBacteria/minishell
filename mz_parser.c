/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:54:01 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/30 10:39:23 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list *mz_first_scan(char *s)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (s[i])
	{
		if (mz_is_space(s[i]))
			i = make_space_nd(&head, s, i);
		else if (mz_is_special(s[i]))
			i = make_special_nd(&head, s, i);
		else
			i = make_word_nd(&head, s, i);
	}
	return (head);
}

t_list	*mz_parser(char *s)
{
	t_list	*head;
	t_list	*tmp;
	t_token	*list;
	
	head = mz_first_scan(s);
	tmp = head;
	// here should be the second scan for syntax errors!
	list = mz_last_scan(head);
	return (head);
}
