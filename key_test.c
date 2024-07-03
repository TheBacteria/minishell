/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:59:17 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/03 12:06:17 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	mz_int_counter(int n)
{
	int	i;
	int	counter;

	counter = 0;
	i = n;
	if (n <= 0)
	{
		counter = 1;
		i = -n;
	}
	while (i > 0)
	{
		counter++;
		i = i / 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	len = mz_int_counter(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

static mz_key_insert(char *final, char *s, char *key)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while(s[i] && s[i] != '\'' && s[i] != '\"')
		{
			final[j] = s[i];
			j++;
			i++;
		}
		if (s[i] == '\'')
			j = mz_next_q(final, s, key, &); // or while still didn't reach quote
		else if (s[i] == '\"')
			j = ;
		i++;
	}
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

int	mz_key_assign(char *s)
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
	final = malloc(mz_size_count(s, key_s));
	mz_key_insert(final, s, key_s);
	
	return (key);
}

int main(int ac, char **av)
{
	int i = 0;
	int	len = ft_strlen(av[1]);
	char *s;
	s = malloc (len + 1);
	while (av[1][i])
	{
		s[i] = av[1][i];
		i++;
	}
	s[i] = '\0';
	i = 0;
	printf("* %s * \n", s);

}