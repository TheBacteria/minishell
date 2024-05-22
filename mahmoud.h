/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mahmoud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:26:40 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 09:39:07 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAHMOUD_H
#define MAHMOUD_H

typedef struct s_list
{
	char			*s;
	struct s_list	*next;
}					t_list;

t_list	*mz_lstnew(char *content);
void	mz_lstadd_back(t_list **lst, t_list *new);
t_list	*mz_lstlast(t_list *lst);
t_list	*env_parse(char **envp);


#endif