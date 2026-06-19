#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"

int	bits_size(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

void	empty_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b);
	}
}

void	algorithm(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int		i;
	t_node	*node;
	int		n;

	i = 0;
	n = stack_a->size;
	while (i < n)
	{
		node = stack_a->top;
		if ((node->index & bit) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int		bit;
	int		trip;

	if (stack_a->size == 0)
		return ;
	bit = 1;
	trip = bits_size(stack_a->size) - 1;
	while (bit <= 1 << trip)
	{
		algorithm(stack_a, stack_b, bit);
		empty_b(stack_a, stack_b);
		bit = bit << 1;
	}
}