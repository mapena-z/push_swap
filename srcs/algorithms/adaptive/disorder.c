/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:08:16 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:15:49 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || stack->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
