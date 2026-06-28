NAME         = push_swap
CHECKER_NAME = checker

CC           = cc
CFLAGS       = -Wall -Wextra -Werror

GREEN   = \033[0;32m
NC      = \033[0m
RED     = \033[0;31m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
WHITE   = \033[1;37m

SRC_ALGORITHMS = srcs/algorithms/simple/turk_sort_utils.c \
                 srcs/algorithms/simple/turk_sort.c \
                 srcs/algorithms/adaptive/adaptive.c \
                 srcs/algorithms/adaptive/disorder.c \
                 srcs/algorithms/complex/radix.c \
                 srcs/algorithms/medium/chunk_sort_utils.c \
                 srcs/algorithms/medium/chunk_sort.c \
                 srcs/algorithms/method/set_algorithm.c \
                 srcs/algorithms/short/short_utils.c \
                 srcs/algorithms/short/short.c

SRC_OPERATIONS = srcs/operations/push.c \
                 srcs/operations/reverse_rotate.c \
                 srcs/operations/rotate.c \
                 srcs/operations/swap.c

SRC_PARSING    = srcs/parsing/parsing_utils.c \
                 srcs/parsing/parsing.c \
                 srcs/parsing/push_carl_propuesta.c \
                 srcs/parsing/push_mpena_orig.c \
                 srcs/parsing/validation.c

SRC_STACK      = srcs/stack/stack_search.c \
                 srcs/stack/stack_utils.c \
                 srcs/stack/stack_nd_management.c

SRC_BENCHMARK  = srcs/benchmark/bench_utils.c \
                 srcs/benchmark/benchmark.c \
                 srcs/benchmark/benchmark_print.c

SRC_COMMON     = $(SRC_ALGORITHMS) $(SRC_OPERATIONS) $(SRC_PARSING) $(SRC_STACK) $(SRC_BENCHMARK)

SRC_MANDATORY  = $(SRC_COMMON) srcs/main.c
SRC_CHECKER    = $(SRC_COMMON) bonus/checker_utils.c bonus/main_checker.c

OBJ_MANDATORY  = $(SRC_MANDATORY:.c=.o)
OBJ_CHECKER    = $(SRC_CHECKER:.c=.o)

LIBFT_DIR      = libft
LIBFT          = $(LIBFT_DIR)/libft.a

INCLUDES       = -Iincludes -Ilibft -Ilibft/ft_printf -Ibonus
RM             = rm -f

TOTAL_OBJ      = $(words $(OBJ_MANDATORY))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_MANDATORY)
	@$(CC) $(CFLAGS) $(OBJ_MANDATORY) $(LIBFT) -o $(NAME)
	@echo ""
	@echo "$(GREEN)push_swap compilation completed!$(NC)"

checker: $(LIBFT) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(CHECKER_NAME)
	@echo "$(GREEN)checker compilation completed!$(NC)"

$(LIBFT):
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

srcs/%.o: srcs/%.c
	@$(eval COMPLETED = $(shell find srcs -name "*.o" 2>/dev/null | wc -l))
	@if [ $(COMPLETED) -eq 0 ]; then \
		echo "$(CYAN)"; \
		echo "   ____  _   _ ____  _   _   ======        ___    ____  "; \
		echo "  |  _ \| | | / ___|| | | | / ___\ \      / / \  |  _ \ "; \
		echo "  | |_) | | | \___ \| |_| | \___  \ \ /\ / / _ \ | |_) |"; \
		echo "  |  __/| |_| |___) |  _  |  ___) |\ V  V / ___ \|  __/ "; \
		echo "  |_|    \___/|____/|_| |_| |____/  \_/\_/_/   \_\_|    "; \
		echo " "; \
		echo "        $(WHITE)By: mapena-z & carlinaq-$(CYAN)                "; \
		echo "$(NC)"; \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@( \
	COMP_SRCS=$$(find srcs -name "*.o" 2>/dev/null | wc -l); \
	if [ $(TOTAL_OBJ) -gt 0 ]; then \
		PERCENTAGE=$$(echo "scale=2; 100 * $$COMP_SRCS / $(TOTAL_OBJ)" | bc); \
		BAR_LENGTH=50; \
		FILLED_LENGTH=$$(echo "$$BAR_LENGTH * $$COMP_SRCS / $(TOTAL_OBJ)" | bc); \
		EMPTY_LENGTH=$$(echo "$$BAR_LENGTH - $$FILLED_LENGTH" | bc); \
		BAR=$$(yes "=" | head -n $$FILLED_LENGTH | tr -d '\n'); \
		EMPTY=$$(yes " " | head -n $$EMPTY_LENGTH | tr -d '\n'); \
		echo -n "$(GREEN)[$$BAR$$EMPTY] $$PERCENTAGE%\r$(NC)"; \
	fi \
	)
	@sleep 0.01

bonus/%.o: bonus/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ_MANDATORY) $(OBJ_CHECKER)
	@find srcs bonus -name "*.o" -type f -delete 2>/dev/null || true
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)Object files cleaned up successfully.$(NC)"

fclean: clean
	@$(RM) $(NAME) $(CHECKER_NAME)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(RED)All binaries completely removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re