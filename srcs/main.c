/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:57:11 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/21 21:42:55 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/parsing.h"
#include "../includes/stack_utils.h"
#include "../includes/algorithms.h"
#include "../includes/benchmark.h"
#include "debug/debug.h"

static void	run_selected_sort(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	if (has_flag(argc, argv, "--simple"))
		insertion_basic(stack_a, stack_b);
	else if (has_flag(argc, argv, "--medium"))
		chunk_sort(stack_a, stack_b);
	else if (has_flag(argc, argv, "--complex"))
		radix(stack_a, stack_b);
	else
		adaptive_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			start_idx;

	if (argc == 1)
		return (0);
	start_idx = first_value_arg(argc, argv);
	if (start_idx == argc)
		return (0);
	stack_a = stack_new('a');
	stack_b = stack_new('b');
	if ((!stack_a || !stack_b)
		|| parse_arguments(argc, argv, start_idx, stack_a) == 1)
		return (stack_free(stack_a, stack_b), 1);
	stack_index(stack_a);
	if (is_bench_mode(argc, argv))
		create_bench(stack_a, stack_b, argc, argv);
	if (is_bench_mode(argc, argv) && !stack_a->bench)
			return (stack_free(stack_a, stack_b), 1);
	if ((stack_a->bench && stack_a->bench->disorder == 0)
		|| (!stack_a->bench && compute_disorder(stack_a) == 0))
	{
		if (stack_a->bench)
			bench_print(stack_a->bench);
		return (bench_free(stack_a->bench), stack_free(stack_a, stack_b), 0);
	}
	set_fd(stack_a, stack_b);
	//stack_print(stack_a); //
	run_selected_sort(stack_a, stack_b, argc, argv);
	bench_print(stack_a->bench);
	//stack_print(stack_a); //
	return (bench_free(stack_a->bench), stack_free(stack_a, stack_b), 0);
}
