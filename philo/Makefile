# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 15:49:58 by bkiskac           #+#    #+#              #
#    Updated: 2025/02/16 16:01:50 by bkiskac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	philo_utils.c \
	parse_input.c \
	data_init.c \
	dinner_start.c \
	monitor.c \
	clean_up.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

main: all clean

.PHONY: all clean fclean re
