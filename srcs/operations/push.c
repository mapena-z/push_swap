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
#include "../stack/stack.h"
#include "operations.h"

void	push(t_stack *stack_out, t_stack *stack_in)
{
	t_node *node_aux;

	if (!stack_out || !stack_in || stack_out->size == 0)
		return ;
	node_aux = stack_out->top->next;
	stack_add_front(stack_in, stack_out->top);
	stack_out->size--;
	stack_out->top = node_aux;
	if (stack_out->size == 0)
		stack_out->bot = NULL;
}

void	pa(t_stack *out, t_stack *in)
{
	push(out, in);
	print_mov(out, 'p');
}
void	pb(t_stack *out, t_stack *in)
{
	push(out, in);
	print_mov(out, 'p');
}