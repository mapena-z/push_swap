/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:30:00 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/26 12:00:00 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/push_swap.h"

/* Prototypes for Turk helpers defined in turk_sort_utils.c */
int		moves_to_top(t_stack *stack, int pos);
int		compute_cost(t_stack *a, t_stack *b, int pos_a, int pos_b);
int		find_insert_pos_b(t_stack *b, int target_index);
t_move	find_cheapest(t_stack *a, t_stack *b);
void	rotate_both_to_top(t_stack *a, t_stack *b, int pos_a, int pos_b);

/* -------------------------------------------------------------------------- */
/*  PHASE 2 — RESTORE B → A                                                   */
/* -------------------------------------------------------------------------- */

/*
** Brings the largest element of B to the top using the shortest path
** (via rotate_pos_to_top), then pushes it to A. Repeated until B empty.
** A ends up sorted ascending since we always pull the current max from B.
*/
static void	restore_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->size > 0)
	{
		pos = stack_max_pos(stack_b);
		rotate_pos_to_top(stack_b, pos);
		pa(stack_a, stack_b);
	}
}

/* -------------------------------------------------------------------------- */
/*  FINAL ROTATION — align sorted A                                            */
/* -------------------------------------------------------------------------- */

/*
** After restoring B→A, rotate so that the overall minimum (index 0)
** is on top. Uses the shared bring_index_to_top helper.
*/
static void	rotate_min_to_top_a(t_stack *stack_a)
{
	if (!stack_a || stack_a->size <= 1)
		return ;
	bring_index_to_top(stack_a, 0);
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
		alg_two(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		alg_three(stack_a);
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