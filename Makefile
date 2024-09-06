NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)  -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
