/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/14 19:29:49 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"

/*
	Necesario tener normalizados los indices.
	Antes del algoritmo:

	el menor número original debe tener index = 0
	el siguiente 1
	...
	el mayor n-1

Esto hace que los chunks sean fáciles.
*/

int	ft_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

int	get_chunk_size(int n)
{
	return (ft_sqrt(n));
}

int	get_chunk_count(int n)
{
	int	count;

	if (n <= 0)
		return (0);
	count = ft_sqrt(n);
	if (count < 1)
		count = 1;
	return (count);
}

void	get_chunk_range(int chunk_id, int chunk_size, int total, int *start, int *end)
{
	*start = chunk_id * chunk_size;
	*end = *start + chunk_size - 1;
}

int	index_in_range(int index, int start, int end)
{
	return (index >= start && index <= end);
}

int	stack_has_index_in_range(t_stack *stack, int start, int end)
{
	t_node *node;

	if (!stack || start > end)
		return (-1);
	node = stack->top;
	while (node)
	{
		if (index_in_range(node->index, start, end))
			return (1);
		node = node->next;
	}
	return (0);
}