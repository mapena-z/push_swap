/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:13:58 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:14:55 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/benchmark.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

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
	if (a->fd != -1)
		ft_putstr_fd("sa\n", a->fd);
	if (a->bench)
	{
		a->bench->ops.n_sa++;
		a->bench->ops.total_ops++;
	}
}

void	sb(t_stack *b)
{
	swap(b);
	if (b->fd != -1)
		ft_putstr_fd("sb\n", b->fd);
	if (b->bench)
	{
		b->bench->ops.n_sb++;
		b->bench->ops.total_ops++;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->fd != -1)
		ft_putstr_fd("ss\n", a->fd);
	if (a->bench)
	{
		a->bench->ops.n_ss++;
		a->bench->ops.total_ops++;
	}
}
