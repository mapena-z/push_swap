/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 05:26:50 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/30 20:09:14 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/parsing.h"
#include "../includes/stack_utils.h"
#include "../includes/algorithms.h"
#include "../includes/benchmark.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (init_and_parse(&stack_a, &stack_b, argc, argv))
		return (1);
	if (!stack_a || !stack_b)
		return (0);
	set_fd(stack_a, stack_b);
	if (has_flag(argc, argv, "--b"))
	{
		stack_a->fd = -1;
		stack_b->fd = -1;
	}
	run_method(stack_a, stack_b, argc, argv);
	bench_print(stack_a->bench);
	if (has_flag(argc, argv, "--b"))
		bench_putlabelnbr_fd("[bench] total_ops: ", stack_a->bench->ops.total_ops, 2);
	free(stack_a->bench);
	stack_free(stack_a, stack_b);
	return (0);
}
