NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I. -I./ft_printf

AR = ar rcs

RM = rm -rf

LIBFT_SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_bzero.c ft_isprint.c ft_strlcpy.c ft_strlcat.c \
                ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_memset.c ft_memcpy.c ft_memmove.c \
                ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
                ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
                ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				get_next_line.c

PRINTF_SOURCES = ft_printf/ft_printf.c ft_printf/ft_print_numbers.c ft_printf/ft_print_words.c ft_printf/utils.c

SOURCES = $(LIBFT_SOURCES) $(PRINTF_SOURCES)

OBJECTS = $(SOURCES:.c=.o)

GREEN  = \033[0;32m
NC     = \033[0m
RED    = \033[0;31m
YELLOW = \033[0;33m
CYAN   = \033[0;36m
WHITE  = \033[1;37m

TOTAL_OBJ = $(words $(OBJECTS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $(OBJECTS)
	@echo ""
	@echo "$(GREEN)libft compilation completed!$(NC)"

%.o: %.c
	@$(eval COMPLETED = $(shell ls -1 *.o ft_printf/*.o 2>/dev/null | wc -l))
	@if [ $(COMPLETED) -eq 0 ]; then \
		echo "$(CYAN)"; \
		echo "  _     _____ ____   ______________ "; \
		echo " | |   |_   _|  _  \|  ____|__   __|"; \
		echo " | |     | | | |_) /| |__     | |   "; \
		echo " | |     | | |  _ < |  __|    | |   "; \
		echo " | |_____| |_| |_) \| |       | |   "; \
		echo " |_____|____ |_____/|_|       |_|   "; \
		echo "                                    "; \
		echo "          $(WHITE)By: mapena-z$(CYAN)           "; \
		echo "$(NC)"; \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(MAKE) -s progress

clean:
	@$(RM) $(OBJECTS)
	@echo "$(YELLOW)Cleaning up object files for libft...$(NC)"

fclean:
	@$(RM) $(OBJECTS) $(NAME)
	@echo "$(RED)libft fully cleaned!$(NC)"

re: fclean all

progress:
	@( \
	COMP_LIB=$$(ls -1 *.o 2>/dev/null | wc -l); \
	COMP_PRN=$$(ls -1 ft_printf/*.o 2>/dev/null | wc -l); \
	COMPLETED=$$((COMP_LIB + COMP_PRN)); \
	if [ $(TOTAL_OBJ) -gt 0 ]; then \
		PERCENTAGE=$$(echo "scale=2; 100 * $$COMPLETED / $(TOTAL_OBJ)" | bc); \
		BAR_LENGTH=50; \
		FILLED_LENGTH=$$(echo "$$BAR_LENGTH * $$COMPLETED / $(TOTAL_OBJ)" | bc); \
		EMPTY_LENGTH=$$(echo "$$BAR_LENGTH - $$FILLED_LENGTH" | bc); \
		BAR=$$(yes "=" | head -n $$FILLED_LENGTH | tr -d '\n'); \
		EMPTY=$$(yes " " | head -n $$EMPTY_LENGTH | tr -d '\n'); \
		echo -n "$(GREEN)[$$BAR$$EMPTY] $$PERCENTAGE%\r$(NC)"; \
	fi \
	)
	@sleep 0.01

.PHONY: all clean fclean re progress