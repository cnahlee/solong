NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Imlx -Ift_libft

# Libraries
LIBFT_DIR = ft_libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)

# Objects
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Rule for compiling .c files into .o files
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Rule for building the final executable
all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_OBJ) $(MLX_FLAGS)

# Rule for building the ft_libft library
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Clean rule to remove all object files and executables
clean:
	rm -f $(OBJECTS) $(LIBFT_OBJ)
	make clean -C $(LIBFT_DIR)

# Full clean rule to remove all files and rebuild
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild rule
re: fclean all
