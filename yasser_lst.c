/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yasser_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:09:46 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/23 15:10:00 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_lstnew(char *cmd)
{
	t_token	*head;

	head = NULL;
	head = (t_token *)malloc(sizeof(t_token));
	if (head == NULL)
		return (NULL);
	head->next = NULL;
	head->previous = NULL;
	head->cmd = cmd;
	head->right = NULL;
	head->left = NULL;
	return (head);
}

t_token	*ft_lstlast(t_token *lst)
{
	t_token	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_token **lst, t_token *new, t_token *pre)
{
	t_token	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		new->previous = pre;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->previous = last;
	}
}
