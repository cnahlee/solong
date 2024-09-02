# Variables for colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

NAME = solong
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar
ARFLAGS = -r
LIBDIR = ./libft
LIBS = -lft

# Targets
all: $(NAME)

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Building the library...$(RESET)"
	@make -C $(LIBDIR)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) -L$(LIBDIR) $(LIBS)
	@echo "$(GREEN)Build complete!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJECTS)
	@cd $(LIBDIR) && $(MAKE) clean
	@echo "$(RED)Clean complete!$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@cd $(LIBDIR) && $(MAKE) fclean
	@echo "$(RED)Remove complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re