# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 18:16:28 by murachid          #+#    #+#              #
#    Updated: 2021/09/12 09:40:31 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -Wall -Wextra -Werror 

SRC = main.c philo_init.c philo_mutex.c philo_threads.c \
philo_times.c philo_tools.c philo_error.c philo_check_death.c \
philo_print.c \

all : $(NAME)

OBJS = $(SRC:.c=.o)

$(NAME): $(SRC)

	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re:	fclean all