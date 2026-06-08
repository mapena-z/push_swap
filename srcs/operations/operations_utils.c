#include "../../includes/push_swap.h"

void print_mov(t_stack *stack, char mov)
{
	if (!stack)
		return ;
	ft_putchar_fd(mov, 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
}