#include "../../includes/push_swap.h"
#include "../stack/stack.h"
#include "operations.h"

void	rotate(t_stack *stack)
{
	t_node *old_top;
	t_node *new_top;

	if (!stack || stack->size <= 1)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	old_top->next = NULL;
	stack->bot->next = old_top;
	stack->bot = old_top;
	stack->top = new_top; 
}
void	ra(t_stack *a)
{
	rotate(a);
	print_mov(a, 'r');
}
void	rb(t_stack *b)
{
	rotate(b);
	print_mov(b, 'r');
}
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}