/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:41:50 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/28 17:39:02 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"
#include "../../../includes/operations.h"
#include "../../../includes/push_swap.h"
#include "../../../includes/stack_utils.h"

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

void	rotate_stack_a(t_stack *stack, int count, int forward)
{
	while (count-- > 0)
	{
		if (forward)
			ra(stack);
		else
			rra(stack);
	}
}

void	rotate_stack_b(t_stack *stack, int count, int forward)
{
	while (count-- > 0)
	{
		if (forward)
			rb(stack);
		else
			rrb(stack);
	}
}

void	rr_pos(t_stack *a, t_stack *b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(a, b);
		(*pos_a)--;
		(*pos_b)--;
	}
}

void	rrr_pos(t_stack *a, t_stack *b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rrr(a, b);
		(*pos_a)--;
		(*pos_b)--;
	}
}
