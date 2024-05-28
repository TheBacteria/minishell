/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:28 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/28 12:09:19 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**mz_addstring(char **org, char *s)
{

}

static char	**mz_addarray(char **org, char **arr)
{

}

char	**mz_arr(char **org, char **arr, char *s, int flag) // 1 to add string, 2 to add array !
{
	if (flag == 1)
		return (mz_addstring(org, s));
	else if (flag == 2)
		return (mz_addarray(org, arr));
	else
	{
		printf("Error!\n mz_arr called with wrong flag!\n");
		return (NULL);
	}
}
