/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mahmoud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:26:40 by mzouine           #+#    #+#             */
/*   Updated: 2024/07/09 11:32:21 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAHMOUD_H
#define MAHMOUD_H

#include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	char			*s;
	int 			nature;
    int				quote;
	int				d_quote;
    char            *key_q;
    char            *key_d_q;
}					t_list;

typedef struct s_info
{
    char    *final;
    int     j;
    int     i;
} t_info;

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

char	**mz_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*mz_lstnew(char *content);
void	mz_lstadd_back(t_list **lst, t_list *new);
t_list	*mz_lstlast(t_list *lst);
t_list	*env_parse(char **envp);
t_token	*mz_parser(char *s);
int		mz_is_space(char c);
int		mz_is_special(char c);
int		make_space_nd(t_list **head, char *s, int i);
int		make_special_nd(t_list **head, char *s, int i);
int		make_word_nd(t_list **head, char *s, int i);
int		make_pipe(t_list **head, char *s, int i);
int		make_in(t_list **head, char *s, int i);
int		make_out(t_list **head, char *s, int i);
int		make_and(t_list **head, char *s, int i);
int		make_quote(t_list **head, char *s, int i);
int		make_dquote(t_list **head, char *s, int i);
int		make_dollar(t_list **head, char *s, int i);
int		make_o_par(t_list **head, char *s, int i);
int		make_c_par(t_list **head, char *s, int i);
int		make_star(t_list **head, char *s, int i);
t_token *mz_last_scan(t_list *head);
void	mz_make_special(t_token **list, t_list **head);
void     mz_make_cmd(t_token **list, t_list **head);
char	**mz_arr(char **org, char **arr, char *s, int flag);
void    mz_syntax(t_list *lst);
int     mz_search(char *s, int i, char c);
size_t	ft_strlen(const char *s);
char	**mz_nl_sp(char const *s, char c, int n);
void	mz_make_redi(t_token **list, t_list **head);
void    mz_splitter(t_token *head);
int     mz_key_assign(char **s);
char	*ft_itoa(int n);
void	mz_joiner(char *s);

#endif