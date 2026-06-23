#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/benchmark.h"

static void reverse_rotate(t_stack *stack)
{
	t_node *old_bot;
	t_node *new_bot;

	if (!stack || stack->size <= 1)
		return;
	new_bot = stack->top;
	while (new_bot->next != stack->bot)
		new_bot = new_bot->next;
	old_bot = stack->bot;
	stack->bot = new_bot;
	stack->bot->next = NULL;
	old_bot->next = stack->top;
	stack->top = old_bot;
}

void rra(t_stack *a)
{
	reverse_rotate(a);
	if (a->fd != -1)
		ft_putstr_fd("rra\n", a->fd);
	//bench_count_rra(a->bench);
	if (a->bench)
	{
		a->bench->ops.n_rra++;
		a->bench->ops.total_ops++;
	}
}

void rrb(t_stack *b)
{
	reverse_rotate(b);
	if (b->fd != -1)
		ft_putstr_fd("rrb\n", b->fd);
	//bench_count_rrb(b->bench);
	if (b->bench)
	{
		b->bench->ops.n_rrb++;
		b->bench->ops.total_ops++;
	}
}

void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (a->fd != -1)
		ft_putstr_fd("rrr\n", a->fd);
	//bench_count_rrr(a->bench);
	if (a->bench)
	{
		a->bench->ops.n_rrr++;
		a->bench->ops.total_ops++;
	}
}
