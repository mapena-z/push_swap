#include "../../includes/push_swap.h"
#include "../../includes/operations.h"

void swap(t_stack *stack)
{
	t_node *first;
	t_node *second;
	if (!stack || stack->size <= 1)
		return;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bot = first;
}

void sa(t_stack *a)
{
	swap(a);
	if (a->fd != -1)
		ft_putstr_fd("sa\n", a->fd);
}

void sb(t_stack *b)
{
	swap(b);
	if (b->fd != -1)
		ft_putstr_fd("sb\n", b->fd);
}

void ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->fd != -1)
		ft_putstr_fd("ss\n", a->fd);
}
