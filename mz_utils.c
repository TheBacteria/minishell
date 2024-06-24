/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:30:52 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/24 14:37:52 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *) malloc(ft_strlen(s1) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	tol;
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		tol = ft_strlen(s) - start;
	else
		tol = len;
	sub = malloc(tol + 1);
	if (!sub)
		return (NULL);
	while (i < tol)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*final;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	j = 0;
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (NULL);
	while (s1[++i])
		final[i] = s1[i];
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = '\0';
	return (final);
}

int	mz_search(char *s, int i, char c)
{
	i += 1;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}
