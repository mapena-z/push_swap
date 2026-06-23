#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/benchmark.h"

static void rotate(t_stack *stack)
{
	t_node *old_top;
	t_node *new_top;

	if (!stack || stack->size <= 1)
		return;
	old_top = stack->top;
	new_top = old_top->next;
	old_top->next = NULL;
	stack->bot->next = old_top;
	stack->bot = old_top;
	stack->top = new_top;
}
void ra(t_stack *a)
{
	rotate(a);
	if (a->fd != -1)
		ft_putstr_fd("ra\n", a->fd);
	//bench_count_ra(a->bench);
	if (a->bench)
	{
		a->bench->ops.n_ra++;
		a->bench->ops.total_ops++;
	}
}

void rb(t_stack *b)
{
	rotate(b);
	if (b->fd != -1)
		ft_putstr_fd("rb\n", b->fd);
	//bench_count_rb(b->bench);
	if (b->bench)
	{
		b->bench->ops.n_rb++;
		b->bench->ops.total_ops++;
	}
}

void rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (a->fd != -1)
		ft_putstr_fd("rr\n", a->fd);
	//bench_count_rr(a->bench);
	if (a->bench)
	{
		a->bench->ops.n_rr++;
		a->bench->ops.total_ops++;
	}
}
