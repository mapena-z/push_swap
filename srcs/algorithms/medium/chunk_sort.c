/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:19 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 19:23:25 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/push_swap.h"
#include "../../../includes/stack_utils.h"

void	prepare_b_for_push(t_stack *stack_b)
{
	int	max_index;

	max_index = stack_max_pos(stack_b);
	rotate_pos_to_top(stack_b, max_index);
}

void	rotate_pos_to_top(t_stack *stack, int pos)
{
	int	count;

	if (!stack || pos < 0 || pos >= stack->size)
		return ;
	count = 0;
	if (pos <= stack->size / 2)
	{
		while (count < pos)
		{
			ra(stack);
			count++;
		}
	}
	else
	{
		while (count < stack->size - pos)
		{
			rra(stack);
			count++;
		}
	}
}

void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int		pos;
	t_node	*node;

	if (!stack_a || !stack_b)
		return ;
	while (stack_has_index_in_range(stack_a, start, end) == 1)
	{
		node = stack_a->top;
		pos = 0;
		while (node && !(node->index >= start && node->index <= end))
		{
			node = node->next;
			pos++;
		}
		if (!node)
			break ;
		rotate_pos_to_top(stack_a, pos);
		prepare_b_for_push(stack_b);
		pb(stack_a, stack_b);
	}
}

void	push_back_best_element(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	pos = stack_max_pos(stack_b);
	rotate_pos_to_top(stack_b, pos);
	pa(stack_a, stack_b);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk_count;
	int	chunk_id;
	int	start;
	int	end;

	if (!stack_a || !stack_b)
		return ;
	chunk_size = ft_sqrt(stack_a->size);
	chunk_count = (stack_a->size + chunk_size - 1) / chunk_size;
	chunk_id = 0;
	while (chunk_id < chunk_count)
	{
		start = chunk_id * chunk_size;
		end = start + chunk_size - 1;
		if (end >= stack_a->size)
			end = stack_a->size - 1;
		push_chunk_to_b(stack_a, stack_b, start, end);
		chunk_id++;
	}
	push_back_to_a(stack_a, stack_b);
}
