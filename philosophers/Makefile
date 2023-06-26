NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES = 	  ./src/actions/*.c \
		  ./src/utils/*.c \
		  ./src/argument_check/*.c \
		  ./src/main.c

all:
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean: 
	@rm -rf $(NAME)

re: fclean all
