/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:10:31 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:12:02 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/operations.h"
#include "../../includes/stack_utils.h"
#include "../../includes/benchmark.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*node_aux;

	if (!src || !dst || src->size == 0)
		return ;
	node_aux = src->top->next;
	stack_add_front(dst, src->top);
	src->size--;
	src->top = node_aux;
	if (src->size == 0)
		src->bot = NULL;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	if (a->fd != -1)
		ft_putstr_fd("pa\n", a->fd);
	if (a->bench)
	{
		a->bench->ops.n_pa++;
		a->bench->ops.total_ops++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	if (b->fd != -1)
		ft_putstr_fd("pb\n", b->fd);
	if (a->bench)
	{
		a->bench->ops.n_pb++;
		a->bench->ops.total_ops++;
	}
}
