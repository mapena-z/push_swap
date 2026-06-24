/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:24 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:40:23 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/algorithms.h"

void	alg_two(t_stack *stack)
{
	if (!stack || stack->size != 2)
		return ;
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	alg_three(t_stack *a)
{
	if (!a || a->size != 3)
		return ;
	sort_three_with_offset(a, 0);
}

void	alg_four(t_stack *a, t_stack *b)
{
	bring_index_to_top(a, 0);
	pb(a, b);
	sort_three_with_offset(a, 1);
	pa(a, b);
}

void	alg_five(t_stack *a, t_stack *b)
{
	bring_index_to_top(a, 0);
	pb(a, b);
	bring_index_to_top(a, 1);
	pb(a, b);
	sort_three_with_offset(a, b->size);
	pa(a, b);
	pa(a, b);
}
