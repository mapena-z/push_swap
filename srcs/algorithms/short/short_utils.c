/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:29 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:40:03 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/algorithms.h"

void	bring_index_to_top(t_stack *a, int target)
{
	int	pos;
	int	moves;
	int	count;

	pos = stack_find_index(a, target);
	if (!a || pos <= 0)
		return ;
	count = 0;
	if (pos <= a->size / 2)
	{
		while (count < pos)
		{
			ra(a);
			count++;
		}
	}
	else
	{
		moves = a->size - pos;
		while (count < moves)
		{
			rra(a);
			count++;
		}
	}
}

void	sort_three_with_offset(t_stack *a, int offset)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index - offset;
	second = a->top->next->index - offset;
	third = a->bot->index - offset;
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
