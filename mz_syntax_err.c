/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_syntax_err2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:44:05 by mzouine           #+#    #+#             */
/*   Updated: 2024/08/17 18:47:55 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	mz_flag2(char c, int flag)
{
	if (c == '\'' && flag == 0)
		return (1);
	else if (c == '\'' && flag == 1)
		return (0);
	else if (c == '\"' && flag == 0)
		return (2);
	else if (c == '\"' && flag == 2)
		return (0);
	else
		return (flag);
}

int	mz_syntax_err(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		flag = mz_flag2(s[i], flag);
		i++;
	}
	if (flag != 0)
	{
		printf("Syntax Error!\n");
		free(s);
		return (1);
	}
	return (0);
}
/*
'ABC'| // SE // CHECK BEFORE JOIN 
(ls)'fsd' // SE // AFTER CPAR: PIPE OR AND OR OR
((')') // SE
*/