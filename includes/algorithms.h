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
int		ft_sqrt(int nb);
int		get_chunk_size(int n);
int		get_chunk_count(int n);
void	get_chunk_range(int chunk_id, int chunk_size, int total, int *start, int *end);
int		index_in_range(int index, int start, int end);
int		stack_has_index_in_range(t_stack *stack, int start, int end);

#endif