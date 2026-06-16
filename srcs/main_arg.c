/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:57:11 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/16 15:54:19 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/stack_utils.h"
#include "../includes/algorithms.h"
#include "debug/debug.h"

static int	load_stack_from_args(t_stack *stack, int argc, char **argv)
{
	int	i;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		node = node_new(ft_atoi(argv[i]), 0);
		stack_add_back(stack, node);
		i++;
	}
	return (0);
}

static int	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*other;

	if (!stack)
		return (1);
	current = stack->top;
	while (current)
	{
		current->index = 0;
		other = stack->top;
		while (other)
		{
			if (current != other && current->value == other->value)
				return (1);
			if (other->value < current->value)
				current->index++;
			other = other->next;
		}
		current = current->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = stack_new('a');
	stack_b = stack_new('b');
	load_stack_from_args(stack_a, argc, argv);
	assign_indices(stack_a);
	/* Introducir algoritmo*/

	//alg_three(stack_a);
	chunk_sort(stack_a, stack_b);
	//insertion_basic(stack_a, stack_b);
	stack_print(stack_a);
	/* ------------------------------- */
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
