/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:57:11 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/21 18:40:24 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/parsing.h"
#include "../includes/stack_utils.h"
#include "../includes/algorithms.h"
#include "../includes/benchmark.h"
#include "debug/debug.h"

static void	run_small_sort(t_stack *stack_a, t_stack *stack_b)
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

static void	run_selected_sort(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	if (stack_a->size <= 5)
	{
		run_small_sort(stack_a, stack_b);
		return ;
	}
	if (has_flag(argc, argv, "--simple"))
		insertion_basic(stack_a, stack_b);
	else if (has_flag(argc, argv, "--medium"))
		chunk_sort(stack_a, stack_b);
	else if (has_flag(argc, argv, "--complex"))
		radix(stack_a, stack_b);
	else if (has_flag(argc, argv, "--adaptive"))
	{
		if (compute_disorder(stack_a) < 0.5)
			insertion_sort(stack_a, stack_b);
		else
			chunk_sort(stack_a, stack_b);
	}
	else
		chunk_sort(stack_a, stack_b);
}



int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_benchmark	*bench;
	int			start_idx;

	stack_a = stack_new('a');
	stack_b = stack_new('b');
	bench = NULL;
	if (!stack_a || !stack_b)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (1);
	}
	stack_a->fd = 1;
	stack_b->fd = 1;
	if (argc == 1)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (0);
	}
	start_idx = first_value_arg(argc, argv);
	if (start_idx == argc)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (0);
	}
	if (parse_arguments(argc, argv, start_idx, stack_a) == 1)
	{
		stack_free(stack_a);
		stack_free(stack_b);
		return (1);
	}
	stack_index(stack_a);
	if (is_bench_mode(argc, argv))
	{
		bench = bench_new();
		if (!bench)
		{
			stack_free(stack_a);
			stack_free(stack_b);
			return (1);
		}
		setup_benchmark(stack_a, bench, argc, argv);
		stack_b->bench = bench;
		stack_b->fd = -1;
	}
	stack_print(stack_a);
	run_selected_sort(stack_a, stack_b, argc, argv);
	if (bench)
		bench_print(bench);
	stack_print(stack_a);
	//bench_free(bench);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
