/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:33:34 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 12:14:51 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*mz_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	mz_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = mz_lstlast(*lst);
	ptr->next = new;
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *) malloc(ft_strlen(s1) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

t_list	*mz_lstnew(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> s = ft_strdup(content);
	new -> next = NULL;
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*final;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	j = 0;
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (NULL);
	while (s1[++i])
		final[i] = s1[i];
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = '\0';
	return (final);
}