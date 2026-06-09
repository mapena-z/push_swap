#include "../../../includes/push_swap.h"
#include "../../../includes/stack_utils.h"

void sort_b(t_stack stack_b)
{
		
}

void insertion_basic(t_stack *stack_a, t_stack *stack_b)
{
	int pos;

	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 0)
	{
		pos = stack_min_pos(stack_a);
		if (pos <= stack_a->size / 2)
			ra_next_big(stack_a, pos);
		else
			rra_next_big(stack_a, stack_a->size - pos);
		pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}