/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_joiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:02 by mzouine           #+#    #+#             */
/*   Updated: 2024/08/23 13:18:17 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	mz_is_ok(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	if (c == '\"' || c == '\'')
		return (1);
	if (c == '\0')
		return (1);
	if (c == '(' || c == ')' || c == '|')
		return (1);
	return (0);
}

static int	mz_swap_qt(char *s, int i, char c)
{
	while (i > 0 && mz_is_ok(s[i - 1]) == 0)
	{
		if (i > 1 && (s[i - 1] == '&' && s[i - 2] == '&'))
			break ;
		s[i] = s[i - 1];
		s[i - 1] = c;
		i--;
	}
	i++;
	while (s[i] != c)
		i++;
	while (s[i] && mz_is_ok(s[i + 1]) == 0)
	{
		if (s[i + 1] && (s[i + 1] == '&' && s[i + 2] == '&'))
			break ;
		s[i] = s[i + 1];
		s[i + 1] = c;
		i++;
	}
	return (i + 1);
}

static char	*mz_trimmer(char *s, int i, int j, int flag)
{
	char	key;
	char	close;
	char	*final;

	// printf("before :%s \nXXXXXXXXXXXXXXXXXXXXXX\n", s); // TO REMOVE !@!!!!!! ' " ' " ' "
	final = malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		flag = mz_flag(s[i], flag);
		if ((s[i] == '\"' || s[i] == '\'')
			&& (s[i + 1] == '\"' || s[i + 1] == '\'') && flag == 0)
		{
			close = s[i];
			key = s[i + 1];
			i = i + 2;
			while (s[i])
			{
				if (s[i] == key)
				{
					if (s[i + 1] == '\'' || s[i + 1] == '\"')
					{
						key = s[i + 1];
						i = i + 2;
						continue ;
					}
					final[j++] = close;
					i++;
					break ;
				}
				else
					final[j++] = s[i++];
			}
		}
		else
			final[j++] = s[i++];
	}
	final[j] = '\0';
	// printf("after :%s \nXXXXXXXXXXXXXXXXXXXXXX\n", final); // TO REMOVE !@!!!!!! '"'"'"
	// exit(1); // REMOVEEEEEE !! 
	
/*
	minishell:'ls"'x"cm'd"
	Key: 0

	'ls"x'  --> -1
	arg_0 ->> ["cm'd"]
	YOU NEED A WAY TO KNOW IF THERE WAS A SPACE OR NOT, SO THAT YASSER KNOW WHEN TO JOIN QUOTES !!!
*/
	return (final);
}

char	*mz_joiner(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
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
	return (s);
}
