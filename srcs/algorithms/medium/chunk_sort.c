/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:19 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:23:43 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/push_swap.h"
#include "../../../includes/stack_utils.h"

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
			rotate_up(stack);
			count++;
		}
	}
	else
	{
		while (count < stack->size - pos)
		{
			reverse_rotate_down(stack);
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
		pb(stack_a, stack_b);
		if (stack_b->size > 1
			&& stack_b->top->index <= start + ((end - start) / 2))
			rb(stack_b);
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
	int	total_size;
	int	start;
	int	end;

	if (!stack_a || !stack_b)
		return ;
	total_size = stack_a->size;
	chunk_size = ft_sqrt(total_size) + 1;
	start = 0;
	end = chunk_size - 1;
	while (stack_a->size > 0)
	{
		if (end >= total_size)
			end = total_size - 1;
		push_chunk_to_b(stack_a, stack_b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
	}
	while (stack_b->size > 0)
		push_back_best_element(stack_a, stack_b);
}
