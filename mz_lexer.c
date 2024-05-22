/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:08:26 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 16:50:21 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_space_nd(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;
	int		n;

	n = i;
	while (mz_is_space(s[i]))
		i++;
	str = ft_substr(s, n, i - n);
	new = mz_lstnew(str);
	free(str);
	new->nature = 32;
	mz_lstadd_back(head, new);
	return (i);
}


int	make_word_nd(t_list **head, char *s, int i)
{
	t_list	*new;
	char	*str;
	int		n;

	n = i;
	while (!mz_is_space(s[i]) && !mz_is_special(s[i]))
		i++;
	str = ft_substr(s, n, i - n);
	new = mz_lstnew(str);
	free(str);
	new->nature = -1;
	mz_lstadd_back(head, new);
	return (i);
}

int	make_special_nd(t_list **head, char *s, int i)
{
	t_list	*new;
	

	if (!mz_is_special(s[i + 1]))
	{
		new = mz_lstnew()
	}

	
}
