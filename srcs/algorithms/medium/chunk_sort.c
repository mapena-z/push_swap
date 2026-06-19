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
		pb(stack_a, stack_b);
		if (stack_b->size > 1 && stack_b->top->index <= start + ((end - start) / 2))
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

int	ft_pos_of_index(t_stack *s, int target)
{
	t_node	*n;
	int		i;

	if (!s || s->size == 0)
		return (-1);
	n = s->top;
	i = 0;
	while (i < s->size)
	{
		if (n->index == target)
			return (i);
		n = n->next;
		i++;
	}
	return (-1);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	next;
	int	window;
	int	idx;

	if (!stack_a || !stack_b)
		return ;
	chunk_size = ft_sqrt(stack_a->size) + 1;
	next = 0;
	window = chunk_size;
	while (stack_a->size > 0)
	{
		idx = stack_a->top->index;
		if (idx <= next)
		{
			pb(stack_a, stack_b);
			if (stack_b->size > 1)
				ra(stack_b);
			next++;
		}
		else if (idx <= next + window)
		{
			pb(stack_a, stack_b);
			next++;
		}
		else
			ra(stack_a);
	}
	while (stack_b->size > 0)
	{
		push_back_best_element(stack_a, stack_b);
	}
}
