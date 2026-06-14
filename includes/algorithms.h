#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

/* Simple algorithms*/
void alg_two(t_stack *stack);
void	alg_three(t_stack *a);
void	alg_four(t_stack *a, t_stack *b);
void	alg_five(t_stack *a, t_stack *b);
void	insertion_basic(t_stack *stack_a, t_stack *stack_b);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b);

/* Utils */
int	ft_sqrt(int nb);

#endif