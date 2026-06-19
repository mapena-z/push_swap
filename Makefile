NAME = push_swap
CHECKER_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

## Common sources (exclude alternate mains so we can pick one main per target)
SRC_COMMON = $(shell find srcs -name '*.c' -type f ! -name 'main.c' ! -name 'main_alg_test.c' ! -name 'main_arg.c' ! -name 'main_checker.c' | sort)

# Default build uses srcs/main.c
SRC = $(SRC_COMMON) srcs/main.c

# 'checker' target uses your checker file inside the bonus folder
SRC_CHECKER = $(SRC_COMMON) $(shell find bonus -name '*.c' -type f | sort)

# 'arg' target uses srcs/main_alg_test.c (test main)
SRC_ALG = $(SRC_COMMON) srcs/main_alg_test.c

# Optional alternate test main
SRC_ARG = $(SRC_COMMON) srcs/main_arg.c

OBJ = $(SRC:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_ALG = $(SRC_ALG:.c=.o)
OBJ_ARG = $(SRC_ARG:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -Ilibft -Ilibft/ft_printf -Ibonus

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

checker: $(LIBFT) $(OBJ_CHECKER)
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(CHECKER_NAME)

arg: $(LIBFT) $(OBJ_ALG)
	$(CC) $(CFLAGS) $(OBJ_ALG) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@find srcs -name '*.o' -type f -delete
	@find bonus -name '*.o' -type f -delete 2>/dev/null || true
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	$(RM) $(NAME) $(CHECKER_NAME)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all checker clean fclean re arg