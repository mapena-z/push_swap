#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

int		check_flags(char *arg);
int		check_split(char *argv, t_stack *stack);
int		parse_arguments(int argc, char **argv, int i, t_stack *stack);
int		is_number(const char *str);
int		check_long(long value);
long	ft_atol(const char *nptr);
void	free_stacks(t_stack *stack);
void	free_words(char **words);
void	ft_push(t_stack *stack, int value);

#endif
