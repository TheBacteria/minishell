# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzouine <mzouine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 09:40:06 by mzouine           #+#    #+#              #
#    Updated: 2024/05/22 10:40:23 by mzouine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = env_parse.c ft_list.c main.c mz_parser.c

OBJS = $(SRC:%.c=%.o)
CC = cc
CFLAGS = #-Wall -Wextra -Werror
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