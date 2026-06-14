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

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

int	get_chunk_size(int n)
{
	return (ft_sqrt(n));
}

int	get_chunk_count(int n, t_stack stack)
{
	return stack.size / n;
}

void	get_chunk_range(int chunk_id, int chunk_size, int total, int *start, int *end)
{

}

int	index_in_range(int index, int start, int end)
{
	return (index >= start && index <= end);
}

int	stack_has_index_in_range(t_stack *stack, int start, int end)
{
	t_node *node;

	node = stack->top;
	while (node)
	{
		if (index_in_range(node->index, start, end))
			return (1);
		node = node->next;
	}
	return (0);
}