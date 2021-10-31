# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 13:38:06 by gmorange          #+#    #+#              #
#    Updated: 2021/10/18 17:06:05 by gmorange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=clang
CFLAGS=-Wall -Werror -Wextra
SRCS=./srcs/main.c \
	 ./srcs/print.c \
	 ./srcs/utils_libft.c \
	 ./srcs/ft_split.c \
	 ./srcs/check_files.c \
	 ./srcs/stock_path.c \
	 ./srcs/destroy.c \
	 ./srcs/check_and_stock_cmds.c \
	 ./srcs/creat_pipes.c \
	 ./srcs/pipe.c \
	 ./srcs/init.c \
	 ./srcs/limiter.c

OBJS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: CFLAGS+=-D BONUS=1
bonus: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
