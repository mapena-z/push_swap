#include "../../includes/push_swap.h"

void	stack_print(t_stack *stack)
{
	t_node *node;

	if (!stack)
		return ;
	ft_putstr_fd("Stack ", 1);
	ft_putchar_fd(stack->name, 1);
	ft_putstr_fd(" (size: ", 1);
	ft_putnbr_fd(stack->size, 1);
	ft_putstr_fd(")\n", 1);
	node = stack->top;
	while (node)
	{
		ft_putnbr_fd(node->value, 1);
		ft_putstr_fd(" (idx:", 1);
		ft_putnbr_fd(node->index, 1);
		ft_putstr_fd(")\n", 1);
		node = node->next;
	}
}

void	stack_print_both(t_stack *a, t_stack *b)
{
	ft_putstr_fd("--- STACK A ---\n", 1);
	stack_print(a);
	ft_putstr_fd("\n--- STACK B ---\n", 1);
	stack_print(b);
}