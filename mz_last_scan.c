/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mz_last_scan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:12:44 by mzouine           #+#    #+#             */
/*   Updated: 2024/06/01 15:16:32 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *mz_last_scan(t_list *head)
{
	t_token	*list;
	
	list = NULL;
	while (head)
	{
		if (head->nature == -1)
		{
			mz_make_cmd(&list, &head);
		}
		else
		{
			mz_make_special(&list, &head);
		}
	}
	return (list);
}
