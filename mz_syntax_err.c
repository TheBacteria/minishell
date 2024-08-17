/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_syntax_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:45:10 by mzouine           #+#    #+#             */
/*   Updated: 2024/08/17 14:04:33 by mzouine          ###   ########.fr       */
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
	else if (c == '(' && flag == 0)
		return (3);
	else if (c == '(' && flag % 3 == 0)
		return (flag + 3);
	else if (c == ')' && flag % 3 == 0)
		return (flag - 3);
	else if (c == ')' && flag == 0)
		return (-1);
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
		if (((flag == 0 || flag % 3 == 0) && (s[i] == '(' && s[i + 1] == ')'))
			|| flag < 0)
			flag = -1;
		if (flag == -1)
			break ;
		i++;
	}
	if (flag != 0)
	{
		free(s);
		s = NULL;
		printf("Syntax Error!\n");
		// exit(1);
		return (1);
	}
	return (0);
}
