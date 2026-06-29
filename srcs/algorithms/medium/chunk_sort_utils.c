/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/29 18:00:00 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/operations.h"
#include "../../../includes/push_swap.h"
#include "../../../includes/algorithms.h"
#include "../../../includes/stack_utils.h"

int	ft_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

int	stack_has_index_in_range(t_stack *stack, int start, int end)
{
	t_node	*node;

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

t_move	find_cheapest_in_range(t_stack *a, t_stack *b, int start, int end)
{
	t_node	*current;
	t_move	best;
	t_move	candidate;
	int		pos_a;

	best.cost = INT_MAX;
	best.pos_a = 0;
	best.pos_b = 0;
	current = a->top;
	pos_a = 0;
	while (current)
	{
		if (current->index >= start && current->index <= end)
		{
			candidate.pos_a = pos_a;
			candidate.pos_b = find_insert_pos_b(b, current->index);
			candidate.cost = compute_cost(a, b,
					candidate.pos_a, candidate.pos_b);
			if (candidate.cost < best.cost)
				best = candidate;
		}
		current = current->next;
		pos_a++;
	}
	return (best);
}

void	rotate_up(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->name == 'b')
		rb(stack);
	else
		ra(stack);
}

void	reverse_rotate_down(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->name == 'b')
		rrb(stack);
	else
		rra(stack);
}
