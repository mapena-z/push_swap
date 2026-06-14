/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:29 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/14 19:01:31 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"

static void	rotate_up_b(t_stack *stack_b, int n)
{
	while (n-- > 0)
		rb(stack_b);
}

static void	rotate_down_b(t_stack *stack_b, int n)
{
	while (n-- > 0)
		rrb(stack_b);
}

static int	find_insertion_pos(t_stack *stack_b, int index)
{
	t_node	*node;
	int		pos;
	int		min_pos;
	int		max_pos;

	if (!stack_b || stack_b->size == 0)
		return (0);
	if (stack_b->size == 1)
		return (0);
	min_pos = stack_min_pos(stack_b);
	max_pos = stack_max_pos(stack_b);
	if (index > stack_get_at(stack_b, max_pos)->index)
		return (max_pos);
	if (index < stack_get_at(stack_b, min_pos)->index)
		return ((min_pos + 1) % stack_b->size);
	node = stack_b->top;
	pos = 0;
	while (node && node->next)
	{
		if (node->index > index && node->next->index < index)
			return (pos + 1);
		node = node->next;
		pos++;
	}
	return (0);
}

static void	prepare_b(t_stack *stack_b, int pos)
{
	if (!stack_b || stack_b->size == 0)
		return ;
	if (pos <= stack_b->size / 2)
		rotate_up_b(stack_b, pos);
	else
		rotate_down_b(stack_b, stack_b->size - pos);
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 0)
	{
		pos = find_insertion_pos(stack_b, stack_a->top->index);
		prepare_b(stack_b, pos);
		pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
