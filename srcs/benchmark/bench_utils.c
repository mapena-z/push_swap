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
	setup_benchmark(stack_a, argc, argv);
	stack_a->bench = bench;
	stack_b->bench = bench;
}

static void	set_names(t_benchmark *bench, char *strat_name, char *strat_complex)
{
	bench->strategy_name = strat_name;
	bench->strategy_complexity = strat_complex;
}

void	setup_benchmark(t_stack *s_a, int argc, char **argv)
{
	t_benchmark *bench;

	if (!s_a->bench)
		return ;
	bench = s_a->bench;
	bench->disorder = compute_disorder(s_a);
	if (s_a->size <= 5)
		set_names(bench, "small-sort", "0(n²)");
	else if (has_flag(argc, argv, "--simple"))
		set_names(bench, "insertion_basic", "0(n²)");
	else if (has_flag(argc, argv, "--medium"))
		set_names(bench, "chunk_sort", "O(n log n)");
	else if (has_flag(argc, argv, "--complex"))
		set_names(bench, "radix", "O(n * k)");
	else if (has_flag(argc, argv, "--adaptive"))
		set_names(bench, "adaptive", "dynamic");
	else
		set_names(bench, "chunk_sort - no_flag", "O(n log n)");
	s_a->bench = bench;
}
