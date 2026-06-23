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

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"

typedef struct s_move_plan
{
	int	rot_a;
	int	rot_b;
	int	dir_a;
	int	dir_b;
	int	cost;
}	t_move_plan;

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	rotate_single(t_stack *stack, int direction)
{
	if (!stack)
		return ;
	if (direction > 0)
	{
		if (stack->name == 'b')
			rb(stack);
		else
			ra(stack);
	}
	else
	{
		if (stack->name == 'b')
			rrb(stack);
		else
			rra(stack);
	}
}

static int	insertion_pos_desc(t_stack *stack_b, int index)
{
	t_node	*node;
	int		pos;
	int		min_pos;
	int		max_pos;
	int		min_index;
	int		max_index;

	if (!stack_b || stack_b->size <= 1)
		return (0);
	min_pos = stack_min_pos(stack_b);
	max_pos = stack_max_pos(stack_b);
	min_index = stack_get_at(stack_b, min_pos)->index;
	max_index = stack_get_at(stack_b, max_pos)->index;
	if (index > max_index || index < min_index)
		return (max_pos);
	node = stack_b->top;
	pos = 0;
	while (node)
	{
		if (node->index < index)
			return (pos);
		node = node->next;
		pos++;
	}
	return (max_pos);
}

static void	update_best_plan(t_move_plan *best, int rot_a, int rot_b,
	int dir_a, int dir_b)
{
	int	cost;

	if (dir_a == dir_b)
		cost = max_int(rot_a, rot_b);
	else
		cost = rot_a + rot_b;
	if (cost < best->cost)
	{
		best->rot_a = rot_a;
		best->rot_b = rot_b;
		best->dir_a = dir_a;
		best->dir_b = dir_b;
		best->cost = cost;
	}
}

static t_move_plan	find_best_plan(t_stack *stack_a, t_stack *stack_b)
{
	t_move_plan	best;
	t_node		*node;
	int			pos_a;
	int			pos_b;
	int			rev_a;
	int			rev_b;

	best.rot_a = 0;
	best.rot_b = 0;
	best.dir_a = 1;
	best.dir_b = 1;
	best.cost = INT_MAX;
	node = stack_a->top;
	pos_a = 0;
	while (node)
	{
		pos_b = insertion_pos_desc(stack_b, node->index);
		rev_a = stack_a->size - pos_a;
		rev_b = stack_b->size - pos_b;
		update_best_plan(&best, pos_a, pos_b, 1, 1);
		update_best_plan(&best, rev_a, rev_b, -1, -1);
		update_best_plan(&best, pos_a, rev_b, 1, -1);
		update_best_plan(&best, rev_a, pos_b, -1, 1);
		node = node->next;
		pos_a++;
	}
	return (best);
}

static void	execute_plan(t_stack *stack_a, t_stack *stack_b, t_move_plan plan)
{
	while (plan.rot_a > 0 && plan.rot_b > 0 && plan.dir_a == plan.dir_b)
	{
		if (plan.dir_a > 0)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		plan.rot_a--;
		plan.rot_b--;
	}
	while (plan.rot_a-- > 0)
		rotate_single(stack_a, plan.dir_a);
	while (plan.rot_b-- > 0)
		rotate_single(stack_b, plan.dir_b);
	pb(stack_a, stack_b);
}

static void	push_back_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->size > 0)
	{
		pos = stack_max_pos(stack_b);
		rotate_pos_to_top(stack_b, pos);
		pa(stack_a, stack_b);
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_move_plan	plan;

	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 0)
	{
		plan = find_best_plan(stack_a, stack_b);
		execute_plan(stack_a, stack_b, plan);
	}
	push_back_sorted(stack_a, stack_b);
}
