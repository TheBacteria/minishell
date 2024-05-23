/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_make_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:47:38 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/23 16:52:46 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mz_make_special(t_token **list, t_list *head)
{
	if (head->nature == 32)
		head = head->next;
	else if (head->nature == 72)
}