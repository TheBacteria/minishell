/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mahmoud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:26:40 by mzouine           #+#    #+#             */
/*   Updated: 2024/05/22 11:59:39 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAHMOUD_H
#define MAHMOUD_H

typedef struct s_list
{
	char			*s;
	int 			nature;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

enum e_token
{
    WORD = -1,
    WHITE_SPACE = ' ',
    QUOTE = '\'',
    DOUBLE_QUOTE = '\"',
    ENV = '$',
    PIPE_LINE = '|',
    MZ_REDIR_IN = '<',
    MZ_REDIR_OUT = '>',
    OPEN_PARANTHESE = '(',
    CLOSE_PARANTHESE = ')',
    STAR = '*',
    MZ_AND, // &&
    MZ_OR, // ||
    HERE_DOC, // <<
    DREDIR_OUT, // >>
};

t_list	*mz_lstnew(char *content);
void	mz_lstadd_back(t_list **lst, t_list *new);
t_list	*mz_lstlast(t_list *lst);
t_list	*env_parse(char **envp);


#endif