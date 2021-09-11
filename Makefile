# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 18:16:28 by murachid          #+#    #+#              #
#    Updated: 2021/09/11 12:12:22 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -pedantic

CFLAGS = -g #-fsanitize=address

SRC = main.c philo_init.c philo_mutex.c philo_threads.c philo_times.c philo_tools.c philo_error.c \

all : $(NAME)

OBJS = $(SRC:.c=.o)

$(NAME): $(SRC)

	$(CC) $(CFLAGS) $(SRC)  -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re:	fclean all