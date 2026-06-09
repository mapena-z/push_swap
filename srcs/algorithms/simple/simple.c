#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"

void alg_two(t_stack *stack)
{
	if (!stack || stack->size != 2)
		return ;
	if (stack->top > stack->bot)
		ra(stack);
}

void alg_three(t_stack *stack_a, t_stack stack_b)
{
	int first;
	int second;
	int third;

	first = stack_a->top->value;
	second =stack_a->top->next->value;
	third = stack_a->bot->value;
	if (first < second )
	{
		if (second < third)
			return ;
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	} 
	
}