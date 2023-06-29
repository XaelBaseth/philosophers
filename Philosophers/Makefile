CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -fsanitize=thread

RM = rm -rf

NAME = philo
SRCS =  src/utils/ft_atoi.c\
		src/utils/all_ate.c\
		src/utils/starved.c\
		src/utils/panic.c\
		src/utils/destroy.c\
		src/utils/get_time.c\
		src/utils/init_forks.c\
		src/input/is_all_digits.c\
		src/input/init_args.c\
		src/philos/init_philos.c\
		src/philos/routine.c\
		src/mandatory/create_threads.c\
		src/mandatory/monitoring.c\
	   	src/mandatory/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o philo

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

run: all clean

.PHONY: all clean fclean re run
