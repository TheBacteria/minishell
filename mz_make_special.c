/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_make_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:47:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/01 17:03:42 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mz_make_special(t_token **list, t_list **head)
{
	char *s;
	char *tmp;
	

	s = NULL;

	if ((*head)->nature == '<' || (*head)->nature == '>')
		mz_make_cmd(list, head);
	else
	{
		ft_lstadd_back(list, ft_lstnew((*head)->s), NULL);
		(*list)->nature = (*head)->nature;
		(*head) = (*head)->next;
	}
	
}
