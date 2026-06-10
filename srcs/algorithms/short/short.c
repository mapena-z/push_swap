#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"

void alg_two(t_stack *stack)
{
	if (!stack || stack->size != 2)
		return ;
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}

void	alg_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->bot->index;
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


void	alg_four(t_stack *a, t_stack *b)
{
	int	pos;

	pos = stack_find_index(a, 0);
	if (pos == 1)
		sa(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(b, a);
	alg_three(a);
	pa(a, b);
}

void	bring_index_to_top(t_stack *a, int target)
{
	int	pos;

	pos = stack_find_index(a, target);
	if (pos == 1)
		sa(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (pos == 4)
		rra(a);
}

void	alg_five(t_stack *a, t_stack *b)
{
	bring_index_to_top(a, 0);
	pb(b, a);
	bring_index_to_top(a, 1);
	pb(a, b);
	alg_three(a);
	pa(a, b);
	pa(a, b);
}