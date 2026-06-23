/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:24 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 18:51:23 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/algorithms.h"

void alg_two(t_stack *stack)
{
	if (!stack || stack->size != 2)
		return ;
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	alg_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->bot->index;
	if (first == 0 && second == 2 && third == 1)
	{
		sa(a);
		ra(a);
	}
	else if (first == 1 && second == 0 && third == 2)
		sa(a);
	else if (first == 1 && second == 2 && third == 0)
		rra(a);
	else if (first == 2 && second == 0 && third == 1)
		ra(a);
	else if (first == 2 && second == 1 && third == 0)
	{
		sa(a);
		rra(a);
	}
}


void	bring_index_to_top(t_stack *a, int target)
{
	int	pos;
	int	moves;
	int	count;

	pos = stack_find_index(a, target);
	if (!a || pos < 0)
		return ;
	if (pos == 0)
		return ;
	if (pos <= a->size / 2)
	{
		count = 0;
		while (count < pos)
		{
			ra(a);
			count++;
		}
	}
	else
	{
		moves = a->size - pos;
		count = 0;
		while (count < moves)
		{
			rra(a);
			count++;
		}
	}
}

void	alg_four(t_stack *a, t_stack *b)
{
	bring_index_to_top(a, 0);
	pb(a, b);
	alg_three(a);
	pa(a, b);
}

void	alg_five(t_stack *a, t_stack *b)
{
	bring_index_to_top(a, 0);
	pb(a, b);
	bring_index_to_top(a, 1);
	pb(a, b);
	alg_three(a);
	pa(a, b);
	pa(a, b);
}