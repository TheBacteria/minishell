/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:39:06 by mzouine           #+#    #+#             */
/*   Updated: 2024/08/17 17:58:33 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_pipe(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;

	if (s[i + 1] == '|')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = 248;
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '|';
		i = i + 1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (i);
}

int	make_in(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;

	if (s[i + 1] == '>')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = '>';
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '>';
		i = i + 1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (i);
}

int	make_out(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;

	if (s[i + 1] == '<')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = '<';
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '<';
		i = i + 1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (i);
}

int	make_and(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;

	if (s[i + 1] == '&')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = 76;
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = -1;
		i = i + 1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (i);
}

int	make_quote(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;
	int		tmp;

	if (s[i + 1] == '\'')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = -1;
		tmp = i + 2;
	}
	else
	{
		tmp = mz_search(s, i, '\'');
		if (tmp == -1)
			tmp = 1;
		str = ft_substr(s, i, tmp - i);
		new = mz_lstnew(str);
		new->nature = -1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (tmp);
}
