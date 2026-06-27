/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:10:00 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/27 23:44:50 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  COST CALCULATION (used by Turk sort)                                       */
/* -------------------------------------------------------------------------- */

/*
** Returns the number of moves to bring element at [pos] in [stack] to top.
** Forward  (ra/rb):  pos moves          when pos <= size/2
** Backward (rra/rrb): size-pos moves    when pos >  size/2
*/
int	moves_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
		return (pos);
	return (stack->size - pos);
}

/*
** Computes the total cost of moving element at pos_a in A and pos_b in B
** simultaneously to their respective tops.
**
** Key optimization: when both rotations go in the same direction,
** we use rr/rrr and pay max(cost_a, cost_b) instead of cost_a + cost_b.
*/
int	compute_cost(t_stack *stack_a, t_stack *stack_b,
			int pos_a, int pos_b)
{
	int	cost_a;
	int	cost_b;
	int	fwd_a;
	int	fwd_b;

	cost_a = moves_to_top(stack_a, pos_a);
	cost_b = moves_to_top(stack_b, pos_b);
	fwd_a = (pos_a <= stack_a->size / 2);
	fwd_b = (pos_b <= stack_b->size / 2);
	if (fwd_a == fwd_b)
		return (cost_a > cost_b ? cost_a : cost_b);
	return (cost_a + cost_b);
}

/* -------------------------------------------------------------------------- */
/*  BEST CANDIDATE SELECTION                                                   */
/* -------------------------------------------------------------------------- */

/*
** B is maintained in descending order (by index) with wrap-around (circular).
** We work with global indices (0 = smallest ... n-1 = largest).
**
** To insert index X: place it so that B remains "descending circular".
** The insertion position is chosen between two elements where
** current.index > X > next.index .
**
** For elements larger than all or smaller than all in B, we insert
** just above the current maximum index in B.
*/
int	find_insert_pos_b(t_stack *stack_b, int target_index)
{
	t_node	*current;
	int		pos;
	int		max_pos;
	int		max_idx;

	if (!stack_b || stack_b->size == 0)
		return (0);
	current = stack_b->top;
	pos = 0;
	max_pos = 0;
	max_idx = INT_MIN;
	while (current)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	/* Index fits between two adjacent elements in the descending sequence */
	current = stack_b->top;
	pos = 0;
	while (current && current->next)
	{
		if (current->index > target_index && current->next->index < target_index)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	/*
	** target_index is greater than max or smaller than min in B:
	** both cases → insert just above the current max-index element.
	*/
	return (max_pos);
}

/*
** Iterates every element in A and finds the one with the lowest total cost
** to be pushed to B in the correct position.
*/
t_move	find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_move	best;
	t_move	candidate;
	int		pos_a;

	best.cost = INT_MAX;
	best.pos_a = 0;
	best.pos_b = 0;
	current = stack_a->top;
	pos_a = 0;
	while (current)
	{
		candidate.pos_a = pos_a;
		candidate.pos_b = find_insert_pos_b(stack_b, current->index);
		candidate.cost = compute_cost(stack_a, stack_b,
				candidate.pos_a, candidate.pos_b);
		if (candidate.cost < best.cost)
			best = candidate;
		current = current->next;
		pos_a++;
	}
	return (best);
}

/* -------------------------------------------------------------------------- */
/*  SYNCHRONIZED ROTATION                                                      */
/* -------------------------------------------------------------------------- */

/*
** Rotates both stacks simultaneously using rr/rrr while both need moves
** in the same direction, then finishes individually.
** This is the core move-saving optimization.
*/

static void	rotate_stack(t_stack *stack, int count, int forward)
{
	while (count-- > 0)
	{
		if (forward)
			ra(stack);
		else
			rra(stack);
	}
}

static void	rotate_stack_b(t_stack *stack, int count, int forward)
{
	while (count-- > 0)
	{
		if (forward)
			rb(stack);
		else
			rrb(stack);
	}
}

// static void rr_pos(t_stack *a, t_stack *b, int *pos_a, int *pos_b)
// {
// 		while (*pos_a > 0 && *pos_b > 0)
// 		{
// 			rr(a, b);
// 			(*pos_a)--;
// 			(*pos_b)--;
// 		}
// }

void	rotate_both_to_top(t_stack *stack_a, t_stack *stack_b,
			int pos_a, int pos_b)
{
	int	fwd_a;
	int	fwd_b;

	fwd_a = (pos_a <= stack_a->size / 2);
	fwd_b = (pos_b <= stack_b->size / 2);
	if (!fwd_a)
		pos_a = stack_a->size - pos_a;
	if (!fwd_b)
		pos_b = stack_b->size - pos_b;
	if (fwd_a && fwd_b)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			//rr_pos(stack_a, stack_b, &pos_a, &pos_b);
			rr(stack_a, stack_b);
			pos_a--;
			pos_b--;
		}
	}
	else if (!fwd_a && !fwd_b)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rrr(stack_a, stack_b);
			pos_a--;
			pos_b--;
		}
	}
	rotate_stack(stack_a, pos_a, fwd_a);
	rotate_stack_b(stack_b, pos_b, fwd_b);
}
