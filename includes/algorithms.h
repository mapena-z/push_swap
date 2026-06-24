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
void	selection_sort(t_stack *stack_a, t_stack *stack_b);
void	turk_sort(t_stack *stack_a, t_stack *stack_b);

/* short*/
void	bring_index_to_top(t_stack *a, int target);
void	sort_three_with_offset(t_stack *a, int offset);

/* Medium algorithm -> Chunk Sort */
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_sqrt(int nb);
void	prepare_b_for_push(t_stack *stack_b);
void	rotate_up(t_stack *stack);
void	reverse_rotate_down(t_stack *stack);
//int		get_chunk_count(int n);
int		stack_has_index_in_range(t_stack *stack, int start, int end);
void	rotate_pos_to_top(t_stack *stack, int pos);
//void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);

/* radix */
void	radix(t_stack *stack_a, t_stack *stack_b);

/* adaptive */
double	compute_disorder(t_stack *stack);
void	adaptive_sort(t_stack *stack_a, t_stack *stack_b);
#endif