/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_joiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:02 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/09 12:21:58 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static    int mz_flag(char c, int flag)
{
    if (c == '\'' && flag == 0)
        return (1);// in single quotes
    else if (c == '\'' && flag == 1)
        return (0);// pure
    else if (c == '\"' && flag == 0)
        return (2);// in double quotes
    else if (c == '\"' && flag == 2)
        return (0);// pure
    else
        return (flag);
}

static int mz_is_ok(char c)
{
	if (c == 32 || (c >= 9 && c <= 13 ))
		return (1);
	if (c == '\"' || c == '\'')
		return (1);
	if (c == '\0')
		return (1);
	return 0;
}

static int	mz_swap_qt(char *s, int i, char c)
{	
	while (i > 0 && mz_is_ok(s[i - 1]) == 0)
	{
		s[i] = s[i - 1];
		s[i - 1] = c;
		i--;
	}
	i++;
	while (s[i] != c)
		i++;
	while (s[i] && mz_is_ok(s[i + 1]) == 0)
	{
		s[i] = s[i + 1];
		s[i + 1] = c;
		i++;
	}
	return (i + 1);
}

void	mz_joiner(char *s)
{
	int	i;
	int flag;
	
	i = 0;
	flag = 0;
	while(s[i])
    {
        flag = mz_flag(s[i], flag);
		if (flag != 0)
		{
			i = mz_swap_qt(s, i, s[i]);
			flag = 0;
		}
		else
			i++;
    }
	
}
