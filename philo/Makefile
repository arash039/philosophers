CC = cc
CR = clang

CFLAGS = -Wall -Wextra -Werror -pthread
LDFLAGS = -lpthread -fsanitize=thread

SRCS = main.c arg.c utils.c utils_forks.c death_check.c end_check.c init.c monitor.c routine.c

OBJS = $(SRCS:.c=.o)

NAME = philo

RACE = race

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#clang -o philo -fsanitize=thread philo.c -lpthread
$(RACE): $(OBJS)
	$(CR) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(RACE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(RACE)

re: fclean all

.PHONY: all clean fclean
