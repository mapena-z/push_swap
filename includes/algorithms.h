/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:21:46 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/28 17:37:56 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

/* Simple algorithms*/
void	alg_two(t_stack *stack);
void	alg_three(t_stack *a);
void	sort_three_with_offset(t_stack *a, int offset);
void	alg_four(t_stack *a, t_stack *b);
void	alg_five(t_stack *a, t_stack *b);

/* Simple -> turk_sort*/
void	turk_sort(t_stack *stack_a, t_stack *stack_b);
void	bring_index_to_top(t_stack *a, int target);
void	rotate_stack_a(t_stack *stack, int count, int forward);
void	rotate_stack_b(t_stack *stack, int count, int forward);
void	rr_pos(t_stack *a, t_stack *b, int *pos_a, int *pos_b);
void	rrr_pos(t_stack *a, t_stack *b, int *pos_a, int *pos_b);
int		moves_to_top(t_stack *stack, int pos);
// Utils
int		moves_to_top(t_stack *stack, int pos);
int		compute_cost(t_stack *a, t_stack *b, int pos_a, int pos_b);
int		find_insert_pos_b(t_stack *b, int target_index);
t_move	find_cheapest(t_stack *a, t_stack *b);
void	rotate_both_to_top(t_stack *a, t_stack *b, int pos_a, int pos_b);

/* Medium algorithm -> Chunk Sort */
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
int		ft_sqrt(int nb);
void	prepare_b_for_push(t_stack *stack_b);
void	rotate_up(t_stack *stack);
void	reverse_rotate_down(t_stack *stack);
int		stack_has_index_in_range(t_stack *stack, int start, int end);
void	rotate_pos_to_top(t_stack *stack, int pos);

/* Complex -> radix sort*/
void	radix(t_stack *stack_a, t_stack *stack_b);

/* adaptive */
double	compute_disorder(t_stack *stack);
void	adaptive_sort(t_stack *stack_a, t_stack *stack_b);

/*select algorithms*/
void	run_method(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	run_small_case(t_stack *stack_a, t_stack *stack_b);

#endif