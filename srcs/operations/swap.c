#include "../../includes/push_swap.h"
#include "../stack/stack.h"
#include "operations.h"

void	swap(t_stack *stack)
{
	t_node *first;
	t_node *second;
	if (!stack || stack->size <= 1)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;	
	if (stack->size == 2)
		stack->bot = first;
}

void	sa(t_stack *a)
{
	swap(a);
	print_mov(a, 's');
}
void	sb(t_stack *b)
{
	swap(b);
	print_mov(b, 's');
}