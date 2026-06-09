/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:10:30 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/08 20:10:31 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/operations.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node *node_aux;

	if (!src || !dst || src->size == 0)
		return ;
	node_aux = src->top->next;
	stack_add_front(dst, src->top);
	src->size--;
	src->top = node_aux;
	if (src->size == 0)
		src->bot = NULL;
}

void	pa(t_stack *src, t_stack *dst)
{
	push(dst, src);
	print_mov(src, 'p');
}
void	pb(t_stack *src, t_stack *dst)
{
	push(dst, src);
	print_mov(src, 'p');
}