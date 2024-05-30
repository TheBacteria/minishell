/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_make_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:46:12 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/30 11:20:47 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	mz_simple(t_token **list, t_list **head)
{
	char *s;
	char *tmp;

	s = NULL;
	while ((*head) && ((*head)->nature == 32 || (*head)->nature == -1))
	{
		tmp = s;
		if ((*head)->nature == 32)
		{
			s = ft_strjoin(s, " ");
			while ((*head)->nature == 32)
				(*head) = (*head)->next;
		}
		else
			s = ft_strjoin(s, (*head)->s);
		free(tmp);
		(*head) = (*head)->next;
	}
	(*list)->args = mz_split(s, " ");
}

void	mz_make_cmd(t_token **list, t_list **head)
{
	char *s;
	char *tmp;

	s = NULL;
	(*list) = ft_lstnew((*head)->s);
	(*head) = (*head)->next;
	while ((*head))
	{
		while ((*head)->nature == 32)
			(*head) = (*head)->next;
		if ((*head)->nature == -1)
			mz_simple(list, head);
	}
}

	// while ((*head))
	// {
	// 	printf("%s --> %i\n", (*head)->s, (*head)->nature);
	// 	(*head) = (*head)->next;
	// }