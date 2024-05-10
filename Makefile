NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = client.c\
		server.c



OBJS = $(SRCS:.c=.o)

$(NAME) = $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 
