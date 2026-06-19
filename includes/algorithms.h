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

/* Medium algorithm -> Chunk Sort */
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_sqrt(int nb);
int		get_chunk_count(int n);
int		stack_has_index_in_range(t_stack *stack, int start, int end);
void	rotate_pos_to_top(t_stack *stack, int pos);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);

/* radix */
void	radix(t_stack *stack_a, t_stack *stack_b);
#endif