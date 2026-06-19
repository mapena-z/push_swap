/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 19:22:32 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/operations.h"
#include "../../../includes/push_swap.h"
#include "../../../includes/algorithms.h"
#include "../../../includes/stack_utils.h"

int ft_sqrt(int n)
{
	int r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

void push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int max_pos;
	int rot_count;

	while (stack_b->size > 0)
	{
		max_pos = stack_max_pos(stack_b);
		rotate_pos_to_top(stack_b, max_pos);
		pa(stack_a, stack_b);
		rot_count = 0;
		while (rot_count < stack_a->size - 1 &&
			   stack_a->top->next &&
			   stack_a->top->index > stack_a->top->next->index)
		{
			rra(stack_a);
			rot_count++;
		}
	}
}

int get_chunk_count(int n)
{
	int chunk_size;
	int chunk_count;

	chunk_size = ft_sqrt(n);
	if (chunk_size <= 0)
		return (0);
	chunk_count = (n + chunk_size - 1) / chunk_size;
	return (chunk_count);
}

int stack_has_index_in_range(t_stack *stack, int start, int end)
{
	t_node *node;

	if (!stack || stack->size == 0 || start > end)
		return (0);
	node = stack->top;
	while (node)
	{
		if (node->index >= start && node->index <= end)
			return (1);
		node = node->next;
	}
	return (0);
}
