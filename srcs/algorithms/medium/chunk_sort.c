/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:19 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/29 18:00:00 by carlinaq         ###   ########.fr       */
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

static void	push_chunk_cheapest(t_stack *a, t_stack *b, int start, int end)
{
	t_move	best;

	while (stack_has_index_in_range(a, start, end))
	{
		best = find_cheapest_in_range(a, b, start, end);
		rotate_both_to_top(a, b, best.pos_a, best.pos_b);
		pb(a, b);
	}
}

static void	restore_sorted_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		rotate_pos_to_top(b, stack_max_pos(b));
		pa(a, b);
	}
	bring_index_to_top(a, 0);
}

void	chunk_sort_sized(t_stack *a, t_stack *b, int chunk_size)
{
	int	total;
	int	start;
	int	end;

	if (!a || !b || a->size <= 1)
		return ;
	if (a->size >= 2)
	{
		pb(a, b);
		pb(a, b);
	}
	total = a->size + b->size;
	start = 0;
	end = chunk_size - 1;
	while (a->size > 0)
	{
		if (end >= total)
			end = total - 1;
		push_chunk_cheapest(a, b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
	}
	restore_sorted_a(a, b);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1)
		return ;
	chunk_sort_sized(a, b, a->size / 5 + 2);
}
