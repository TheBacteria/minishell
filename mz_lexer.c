/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:08:26 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 16:27:10 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	make_space_nd(t_list **head, char *s, int i)
{
	t_list	*new;

	while (mz_is_space(s[i]))
	{
		
	}
	new->nature = 32;
}

int	make_special_nd(t_list **head, char *s, int i)
{
	t_list	*new;

	while (mz_is_space(s[i]))
	{
		
	}
}

int	make_word_nd(t_list **head, char *s, int i)
{
	t_list	*new;

	while (!mz_is_space(s[i]) && !mz_is_special(s[i]))
	{
		
	}
	new->nature = -1;
}