#include "../../includes/push_swap.h"
#include "../../includes/operations.h"

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
void    ra(t_stack *a, int print)
{
    rotate(a);
    if (print)
        ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack *b, int print)
{
    rotate(b);
    if (print)
        ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack *a, t_stack *b, int print)
{
    rotate(a);
    rotate(b);
    if (print)
        ft_putstr_fd("rr\n", 1);
}
