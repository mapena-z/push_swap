/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:48:58 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/25 11:20:28 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/algorithms.h"
#include "../../../includes/benchmark.h"
#include "../../../includes/parsing.h"
#include "../../../includes/stack_utils.h"

void	run_small_case(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		alg_two(stack_a);
	else if (stack_a->size == 3)
		alg_three(stack_a);
	else if (stack_a->size == 4)
		alg_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		alg_five(stack_a, stack_b);
}

void	run_method(t_stack *stack_a, t_stack *stack_b,
		int argc, char **argv)
{
	double	disorder;

	if (stack_a->bench)
		disorder = stack_a->bench->disorder;
	else
		disorder = compute_disorder(stack_a);
	if (disorder == 0)
		return ;
	if (stack_a->size <= 5)
		run_small_case(stack_a, stack_b);
	else if (has_flag(argc, argv, "--simple"))
		turk_sort(stack_a, stack_b);
	else if (has_flag(argc, argv, "--medium"))
		chunk_sort(stack_a, stack_b);
	else if (has_flag(argc, argv, "--complex"))
		radix(stack_a, stack_b);
	else
		adaptive_sort(stack_a, stack_b);
}
