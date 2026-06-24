/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:30:00 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:46:14 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	VER SI PUEDE HACERSE CON LAS FUNCIONES AUXILIARES QUE YA TENEMOS

*/
#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/push_swap.h"

/* -------------------------------------------------------------------------- */
/*  COST CALCULATION                                                           */
/* -------------------------------------------------------------------------- */

/*
** Returns the number of moves to bring element at [pos] in [stack] to top.
** Forward  (ra/rb):  pos moves          when pos <= size/2
** Backward (rra/rrb): size-pos moves    when pos >  size/2
*/
static int	moves_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
		return (pos);
	return (stack->size - pos);
}

/*
** B is maintained in descending order with wrap-around (circular).
** Example B top→bot: [90, 70, 50, 30] — descending.
**
** To insert value=60: goes between 70 and 50 → pos 2 (after rb twice, pb).
** To insert value=95: greater than all → goes on top after rotating max to top.
** To insert value=10: smaller than all → goes just above the max (same case).
**
** The "smaller than all" and "greater than all" cases both resolve to
** placing the element just above the current maximum of B.
*/
static int	find_insert_pos_b(t_stack *stack_b, int value)
{
	t_node	*current;
	int		pos;
	int		max_pos;
	int		max_val;
	int		min_val;

	if (!stack_b || stack_b->size == 0)
		return (0);
	current = stack_b->top;
	pos = 0;
	max_pos = 0;
	max_val = INT_MIN;
	min_val = INT_MAX;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = pos;
		}
		if (current->value < min_val)
			min_val = current->value;
		current = current->next;
		pos++;
	}
	/* Value fits between two adjacent elements in the descending sequence */
	current = stack_b->top;
	pos = 0;
	while (current && current->next)
	{
		if (current->value > value && current->next->value < value)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	/*
	** Value is greater than max or smaller than min:
	** both cases → insert just above the max element.
	** After rotating max to top, pb places the new element correctly.
	*/
	return (max_pos);
}

/*
** Computes the total cost of moving element at pos_a in A and pos_b in B
** simultaneously to their respective tops.
**
** Key optimization: when both rotations go in the same direction,
** we use rr/rrr and pay max(cost_a, cost_b) instead of cost_a + cost_b.
*/
static int	compute_cost(t_stack *stack_a, t_stack *stack_b,
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
** Iterates every element in A and finds the one with the lowest total cost
** to be pushed to B in the correct position.
*/
static t_move	find_cheapest(t_stack *stack_a, t_stack *stack_b)
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
		candidate.pos_b = find_insert_pos_b(stack_b, current->value);
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
static void	rotate_both_to_top(t_stack *stack_a, t_stack *stack_b,
			int pos_a, int pos_b)
{
	int	fwd_a;
	int	fwd_b;

	fwd_a = (pos_a <= stack_a->size / 2);
	fwd_b = (pos_b <= stack_b->size / 2);
	if (fwd_a && fwd_b)
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(stack_a, stack_b);
			pos_a--;
			pos_b--;
		}
	}
	else if (!fwd_a && !fwd_b)
	{
		pos_a = stack_a->size - pos_a;
		pos_b = stack_b->size - pos_b;
		while (pos_a > 0 && pos_b > 0)
		{
			rrr(stack_a, stack_b);
			pos_a--;
			pos_b--;
		}
	}
	else
	{
		if (fwd_a)
			pos_a = pos_a;
		else
			pos_a = stack_a->size - pos_a;
		if (fwd_b)
			pos_b = pos_b;
		else
			pos_b = stack_b->size - pos_b;
	}
	/* Finish remaining individual rotations for A */
	if (fwd_a)
		while (pos_a-- > 0)
			ra(stack_a);
	else
		while (pos_a-- > 0)
			rra(stack_a);
	/* Finish remaining individual rotations for B */
	if (fwd_b)
		while (pos_b-- > 0)
			rb(stack_b);
	else
		while (pos_b-- > 0)
			rrb(stack_b);
}

/* -------------------------------------------------------------------------- */
/*  PHASE 2 — RESTORE B → A                                                   */
/* -------------------------------------------------------------------------- */

/*
** Finds the position of the maximum value in stack B.
static int	stack_max_pos(t_stack *stack)
{
	t_node	*current;
	int		pos;
	int		max_pos;
	int		max_val;

	current = stack->top;
	pos = 0;
	max_pos = 0;
	max_val = INT_MIN;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

*/
/*
** Brings the largest element of B to the top using the shortest path,
** then pushes it to A. Repeated until B is empty.
** A ends up sorted ascending since we always pull the max from B.
*/
static void	restore_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	moves;

	while (stack_b->size > 0)
	{
		pos = stack_max_pos(stack_b);
		if (pos <= stack_b->size / 2)
		{
			moves = pos;
			while (moves-- > 0)
				rb(stack_b);
		}
		else
		{
			moves = stack_b->size - pos;
			while (moves-- > 0)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

/* -------------------------------------------------------------------------- */
/*  FINAL ROTATION — align sorted A                                            */
/* -------------------------------------------------------------------------- */

/*
** After restoring B→A, the smallest element may not be at the top.
** Finds it and rotates A so the minimum is on top (sorted ascending).
*/
static void	rotate_min_to_top_a(t_stack *stack_a)
{
	int	pos;
	int	moves;

	pos = stack_min_pos(stack_a);
	if (pos == 0)
		return ;
	if (pos <= stack_a->size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(stack_a);
	}
	else
	{
		moves = stack_a->size - pos;
		while (moves-- > 0)
			rra(stack_a);
	}
}

/*
** Sorts exactly 3 elements in stack A using at most 2 moves.
** Covers all 6 permutations.
**
** Positions:  top=a, mid=b, bot=c
**
**  a b c  → already sorted          → nothing
**  a c b  → sa + rra                (swap top two, then bring c up)
**  b a c  → sa                      (swap top two)
**  b c a  → rra                     (rotate backward once)
**  c a b  → ra                      (rotate forward once)
**  c b a  → sa + ra                 (swap top two, then rotate forward)
*/
static void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || stack_a->size != 3)
		return ;
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a < b && b < c)
		return ;
	if (a < b && b > c && a < c)
	{ sa(stack_a); rra(stack_a); }
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		rra(stack_a);
	else if (a < b && b > c && a > c)
		ra(stack_a);
	else if (a > b && b > c)
	{ sa(stack_a); ra(stack_a); }
}

/* -------------------------------------------------------------------------- */
/*  ENTRY POINT                                                                */
/* -------------------------------------------------------------------------- */

/*
** Turk Algorithm for push_swap — targets < 5500 moves for 500 elements.
**
** Phase 1 (A → B): For each element in A, compute the cheapest move
**   considering both its position in A and its target position in B.
**   Use rr/rrr when both stacks rotate in the same direction (saves moves).
**   Push to B. B is maintained in descending order.
**
** Phase 2 (B → A): Pull the maximum of B to top (shortest path) and pa.
**   A ends up sorted ascending.
**
** Phase 3: Rotate A so the minimum sits on top.
*/
void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_move	best;

	if (!stack_a || !stack_b || stack_a->size <= 1)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	/* Bootstrap: 2 elementos en B para que find_insert_pos_b tenga referencia */
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	/* Vaciar A completamente en B manteniendo B en orden descendente circular */
	while (stack_a->size > 0)
	{
		best = find_cheapest(stack_a, stack_b);
		rotate_both_to_top(stack_a, stack_b, best.pos_a, best.pos_b);
		pb(stack_a, stack_b);
	}
	/* B está en orden descendente circular → al sacar el max cada vez, A queda ascendente */
	restore_b_to_a(stack_a, stack_b);
	rotate_min_to_top_a(stack_a);
}