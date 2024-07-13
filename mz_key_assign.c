/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_key_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:19:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/13 15:15:29 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	mz_get_key(void)
{
	int	random;
	int	key;
	int	result;

	random = open("/dev/urandom", O_RDONLY);
	if (random < 0)
		return (0);
	result = read(random, &key, sizeof(key));
	if (result < 0)
	{
		close(random);
		return (0);
	}
	close(random);
	return (key);
}

int	mz_flag(char c, int flag)
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

static int	mz_size_count(char *s, char *key_s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '$')
			j++;
		i++;
	}
	j = j * (ft_strlen(key_s) + 1) * 2;
	j = j + ft_strlen(s) + 1;
	return (j);
}

int	mz_key_assign(char **s)
{
	int		key;
	char	*key_s;
	t_info	info;
	char	*key_half;
	int		i;

	i = 0;
	key = mz_get_key();
	if (key < 0)
		key = key * -1;
	key_s = ft_itoa(key);
	key_half = ft_itoa(key / 2);
	info.final = malloc(mz_size_count(*s, key_s));
	mz_key_insert(&info, *s, key_s, key_half);
	*s = info.final;
	return (key);
}
