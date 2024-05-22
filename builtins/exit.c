/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:33:51 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/04 17:58:17 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	main(void)
{
	pid_t	process_pid;

	process_pid = getpid();
	kill(process_pid, SIGTERM);
	return (0);
}
