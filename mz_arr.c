/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:01:28 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/28 12:42:46 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**freemem(char **final)
{
	int	i;

	i = 0;
	if (final)
	{
		while (final[i])
		{
			free(final[i]);
			i++;
		}
		free(final);
	}
	return (NULL);
}

static int	mz_arr_counter(char **org)
{
	int	i;

	i = 0;
	while (org[i])
		i++;

	return (i);
}

static char	**mz_addstring(char **org, char *s, int size)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc((size + 1 + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = org[i];
		if (!new[i])
			return (freemem(new));
		i++;
	}
	new[i] = s;
	if (!new[i])
		return (freemem(new));
	new[i + 1] = NULL;
	return (new);
}

static char	**mz_addarray(char **org, char **arr, int size)
{

}

char	**mz_arr(char **org, char **arr, char *s, int flag) // 1 to add string, 2 to add array !
{
	if (flag == 1)
		return (mz_addstring(org, s, mz_arr_counter(org)));
	else if (flag == 2)
		return (mz_addarray(org, arr, mz_arr_counter(org)));
	else
	{
		printf("Error!\n mz_arr called with wrong flag!\n");
		return (NULL);
	}
}
