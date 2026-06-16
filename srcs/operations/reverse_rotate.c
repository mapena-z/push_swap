#include "../../includes/push_swap.h"
#include "../../includes/operations.h"

void reverse_rotate(t_stack *stack)
{
	t_node *old_bot;
	t_node *new_bot;

	if (!stack || stack->size <= 1)
		return ;
	new_bot = stack->top;
	while (new_bot->next != stack->bot)
		new_bot = new_bot->next;
	old_bot = stack->bot;
	stack->bot = new_bot;
	stack->bot->next = NULL;
	old_bot->next = stack->top;
	stack->top = old_bot;
}

void    rra(t_stack *a, int print)
{
    reverse_rotate(a);
    if (print)
        ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack *b, int print)
{
    reverse_rotate(b);
    if (print)
        ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack *a, t_stack *b, int print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        ft_putstr_fd("rrr\n", 1);
}
