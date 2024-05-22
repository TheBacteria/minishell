/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:20:39 by ymassiou          #+#    #+#             */
/*   Updated: 2024/05/20 13:27:58 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
#define TREE_H

#define QUEUE 13
#define STACK 37
#define R_L 14
#define L_R 41

#define COMMAND "command"
#define PIPE "pipe"
#define AND "and"
#define OR "or"
#define OPEN_PAR "opa"
#define CLOSE_PAR "cpa"
#define REDIR_OUT "out"
#define REDIR_IN "in"
#define APPEND "append"
#define HEREDOC "hrdoc"
#define WILD_CARD "wc"
#define QUOTES "quotes"
#define SINGLE_QUOTES "s_quotes"

#define LIST			"linked list"

typedef struct s_tree t_tree;
typedef struct s_shell t_shell;

typedef struct s_redir
{
	char *file;
	struct s_redir *next;
} t_redir;

typedef struct s_token
{
	struct s_token *next;
	struct s_token *previous;
	struct s_token *right;
	struct s_token *left;
	char *cmd;
	char **args;
	char *nature;
	int priority;
	char *in;
	char *out;
	int fd_in;
	int fd_out;
	t_redir *redirs_out;
	t_redir *redirs_in;
} t_token;

 typedef struct s_tree
 {
	t_token *info;
	struct s_tree *right;
	struct s_tree *left;
 } t_tree;
/***************************************/

void TEST_setto(t_token *p);

/***************************************/
int		ft_lstsize(t_token *lst);
t_token	*token_clone(t_token *token);
t_token	*ft_lstnew(char *cmd, int type);
t_token	*ft_lstlast(t_token *lst);
void	ft_lstadd_front(t_token **lst, t_token *new);
void	ft_lstadd_back(t_token **lst, t_token *new, t_token *pre);
size_t	ft_strcmp(char *s1, char *s2);
void	push(t_token **head_a, t_token **head_b);
t_tree	*create_leaf(t_token *info);
void	create_branch(t_tree **tree, t_token *left_info, t_token *right_info);
void	pop_push(t_token **stack_last, t_token **exp_last, t_token **stack_head);
void	print_stack(t_token *stack);
void	pop(t_token **stack_head);
void	add_leaf(t_tree **intern, t_tree *left, t_tree *right);
char	**ft_split(char const *s, char c);
t_token	*token_clone(t_token *token);
void print_stack_s(t_token *stack);
void	*ft_free(char **to_free, size_t elements, int flag);
void ft_tree(t_token *input, t_shell *data);
void print2D(t_token* root);

#endif

