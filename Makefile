# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 09:40:06 by mzouine           #+#    #+#              #
#    Updated: 2024/07/01 18:09:29 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = env_parse.c mz_lexer.c ft_list.c mz_make_cmd.c lexer_utils1.c mz_make_special.c\
		lexer_utils2.c mz_parser.c main.c mz_utils.c mz_checker.c yasser_lst.c mz_last_scan.c\
		mz_split.c mz_arr.c mz_syntax.c mz_nul_split.c mz_make_redi.c mz_splitter.c

OBJS = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
RM = rm -f
HEADER = minishell.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re