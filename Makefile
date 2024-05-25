NAME = client server
B_NAME = client_bonus server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c 
B_SRCS = server_bonus.c client_bonus.c

B_OBJS = $(B_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(word 2, $^) -o client
	$(CC) $(CFLAGS) $(word 1, $^) -o server

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(word 2, $^) -o client_bonus
	$(CC) $(CFLAGS) $(word 1, $^) -o server_bonus

bonus: $(B_NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re: fclean $(NAME) $(B_NAME)

.PHONY: all clean fclean re 
