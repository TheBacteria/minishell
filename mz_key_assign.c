/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_key_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:19:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/04 20:03:20 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int mz_get_key(void)
{
    int random;
    int key;
	int result;

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

static	int mz_flag(char c, int flag)
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

static int mz_next_q(char *final, int j, char *key, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		final[j] = '$';
		return (j + 1);
	}
	else if (flag == 0)
	{
		final[j++] = '-';
		while (key[i])
			final[j++] = key[i++];
		final[j] = '\0';
		return (j);
	}
	else if (flag == 2)
	{
		while (key[i])
			final[j++] = key[i++];
		return (j);
	}
	else
		return (-1);
}

static void mz_key_insert(char *final, char *s, char *key)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	while(s[i])
	{
		flag = mz_flag(s[i], flag);
		if (s[i] == '$')
		{
			if (s[i + 1] == '\"' || s[i + 1] == '\'')
				j = mz_next_q(final, j, key, 1);
			else
				j = mz_next_q(final, j, key, flag);
			i++;
		}
		else
		{
			final[j] = s[i];
			i++;
			j++;
		}
	}
	final[j] = '\0';
}

static int mz_size_count(char *s, char *key_s)
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
	j = j * ft_strlen(key_s);
	j = j + ft_strlen(s) + 1;
	return (j);
}

int	mz_key_assign(char **s)
{
	int		key;
	char	*key_s;
	char	*final;
	int		i;

	i = 0;
	key = mz_get_key();
	if (key < 0)
		key = key * -1;
	key_s = ft_itoa(key);
	final = malloc(mz_size_count(*s, key_s));
	mz_key_insert(final, *s, key_s);
	// free(*s);
	*s = final;
	return (key);
}

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int	len = ft_strlen(av[1]);
// 	char *s;
// 	int key;
// 	s = malloc (len + 1);
// 	while (av[1][i])
// 	{
// 		s[i] = av[1][i];
// 		i++;
// 	}
// 	s[i] = '\0';
// 	i = 0;
// 	printf("Before= * %s * \n", s);
// 	key = mz_key_assign(&s);
// 	printf("Afterr= * %s * \n->>> %i", s, key);
// }
//echo $pasd "adsad $home sda" 'asdas $pfe '