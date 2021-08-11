NAME = philo

CC = gcc -pedantic

CFLAGS = -g -fsanitize=address

SRC = *.c

all : $(NAME)

$(NAME): $(SRC)
	
	$(CC)  $(SRC)  -o $(NAME)

clean:
	no file clean

fclean:
	rm -rf $(NAME)

re:	fclean all