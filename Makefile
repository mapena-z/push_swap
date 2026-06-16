NAME = push_swap

CC = cc
CFLAGS = #-Wall -Wextra -Werror

## common sources (exclude alternate mains so we can pick one main per target)
SRC_COMMON = $(shell find srcs -name '*.c' -type f ! -name 'main.c' ! -name 'main_alg_test.c' ! -name 'main_arg.c' | sort)

# default build uses srcs/main.c
SRC = $(SRC_COMMON) srcs/main.c

# 'arg' target uses srcs/main_alg_test.c (test main)
SRC_ALG = $(SRC_COMMON) srcs/main_alg_test.c

# optional alternate test main (if you have srcs/main_arg.c)
SRC_ARG = $(SRC_COMMON) srcs/main_arg.c
OBJ = $(SRC:.c=.o)
OBJ_ALG = $(SRC_ALG:.c=.o)
OBJ_ARG = $(SRC_ARG:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -Ilibft -Ilibft/ft_printf

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

arg: $(LIBFT) $(OBJ_ALG)
	$(CC) $(CFLAGS) $(OBJ_ALG) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	find srcs -name '*.o' -type f -delete
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
