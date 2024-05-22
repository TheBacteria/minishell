/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:24:34 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/04 17:57:28 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int	main(int ac, char **av)
{
	char	*s;

	if (ac > 1)
	{
		printf("pwd: too many arguments\n");
		exit(1);
	}
	s = getcwd(NULL, 0);
	printf("%s\n", s);
}
