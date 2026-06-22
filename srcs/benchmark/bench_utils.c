/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:05:58 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/21 21:21:48 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/algorithms.h"
#include "../../includes/benchmark.h"
#include "../../includes/push_swap.h"
#include "../../includes/parsing.h"
#include "../../includes/stack_utils.h"

int	is_bench_mode(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}

void create_bench(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	t_benchmark *bench;

	if (!stack_a || !stack_b)
		return ;
	bench = bench_new();
	if (!bench)
		return ;
	stack_a->bench = bench;
	stack_b->bench = bench;
	setup_benchmark(stack_a, argc, argv);
}

static void	set_names(t_benchmark *bench, char *strat_name, char *strat_complex)
{
	bench->strategy_name = strat_name;
	bench->strategy_complexity = strat_complex;
}

static void	set_adaptive_choice(t_benchmark *bench, char *strategy, char *complexity)
{
	bench->strategy_name = "adaptive";
	bench->adaptive_strategy = strategy;
	bench->strategy_complexity = complexity;
}

void	setup_benchmark(t_stack *s_a, int argc, char **argv)
{
	t_benchmark *bench;

	if (!s_a->bench)
		return ;
	bench = s_a->bench;
	bench->disorder = compute_disorder(s_a);
	bench->adaptive_strategy = NULL;
	if (bench->disorder == 0)
	{
		set_names(bench, "already_sorted", "0 moves");
		return ;
	}
	if (has_flag(argc, argv, "--simple"))
		set_names(bench, "insertion_basic", "0(n²)");
	else if (has_flag(argc, argv, "--medium"))
		set_names(bench, "chunk_sort", "O(n log n)");
	else if (has_flag(argc, argv, "--complex"))
		set_names(bench, "radix", "O(n * k)");
	else if (bench->disorder < 0.2)
		set_adaptive_choice(bench, "insertion_sort", "O(n)");
	else if (bench->disorder < 0.5)
		set_adaptive_choice(bench, "chunk_sort", "O(n sqrt(n))");
	else
		set_adaptive_choice(bench, "radix", "O(n log n)");
	s_a->bench = bench;
}
