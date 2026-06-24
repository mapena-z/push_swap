/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:39:50 by carlinaq         ###   ########.fr       */
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

void	prepare_b_for_push(t_stack *stack_b)
{
	int	max_index;

	max_index = stack_max_pos(stack_b);
	rotate_pos_to_top(stack_b, max_index);
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
