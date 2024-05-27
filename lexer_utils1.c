/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:39:06 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/23 16:32:02 by mzouine          ###   ########.fr       */
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
		new->nature = '>';     //124
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '>'; // '>'
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
		new->nature = '<'; // 120
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '<'; // '<'
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
		new->nature = '&';
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

	if (s[i + 1] == '\'')
	{
		str = ft_substr(s, i, 2);
		new = mz_lstnew(str);
		new->nature = 78;
		i = i + 2;
	}
	else
	{
		str = ft_substr(s, i, 1);
		new = mz_lstnew(str);
		new->nature = '\'';
		i = i + 1;
	}
	free(str);
	mz_lstadd_back(head, new);
	return (i);
}
