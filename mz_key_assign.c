/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_key_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:19:07 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/02 20:47:26 by mzouine          ###   ########.fr       */
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



int	mz_key_assign(char *s)
{
	int		key;
	int		i;

	i = 0;
	key = mz_get_key();
	if (key < 0)
		key = key * -1;
	while (s[i])
	{
		i++;
	}
	return (key);
}
//echo $pasd "adsad $home sda" 'asdas $pfe '