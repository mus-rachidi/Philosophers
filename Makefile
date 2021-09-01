# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 18:16:28 by murachid          #+#    #+#              #
#    Updated: 2021/08/31 18:16:29 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -pedantic

CFLAGS = -g -fsanitize=address 

SRC = *.c

all : $(NAME)

$(NAME): $(SRC)

	$(CC) $(CFLAGS) $(SRC)  -o $(NAME)

clean:
	no file clean

fclean:
	rm -rf $(NAME)

re:	fclean all