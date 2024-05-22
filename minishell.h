/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:41:53 by ymassiou          #+#    #+#             */
/*   Updated: 2024/05/22 09:34:25 by mzouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include "tree.h"
#include "mahmoud.h"

#define TREE 3
#define DOUBLE_LIST 2
#define READ 0
#define WRITE 1

typedef struct s_token t_token;

typedef struct s_trash
{
	void *to_free;
	struct s_trash *next;
} t_trash;

typedef struct s_shell
{
	int in_par;
	int def_in;
	int def_out;
	int to_close;
	int status;
	char **envp;
	t_token *the_tree;
} t_shell;

void op_gen(t_token *arriving, t_token **exp, t_token **stack, t_shell *main);
void filter(t_token *infix, t_token **exp, t_token **stack, t_shell *main);
void handle_prio(t_token **exp, t_token **stack, t_token *arriving);
void	putstr_fd(char *msg, int fd);
void	lst_free(t_token *head);
int	get_length(char **array);
int  pipe_line(t_token *token, t_shell *data);
void	dfs_tree(t_token *root, t_shell *data);
int exec_child(t_token *token, t_shell *data);
void    update_status(t_shell *data);
void    and_handler(t_token *token, t_shell *data);
void    or_handler(t_token *token, t_shell *data);
void infix_to_postfix(t_token *infix, t_token **exp, t_token **stack, t_shell *data);
char	*check_command(char *command, char **paths, int *flag);



int	mz_parser(char *s);

#endif
