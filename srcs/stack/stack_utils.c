/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:55 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/21 21:15:16 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void set_fd(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench)
{

	if (bench)
	{
		stack_a->bench = bench;
		stack_b->bench = bench;
		stack_a->fd = -1;
		stack_b->fd = -1;
	}else
	{
		stack_a->fd = 1;
		stack_b->fd = 1;
	}
}

t_stack	*stack_new(char name)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return(NULL);
	stack->name = name;
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
	stack->bench = NULL;
	return (stack);
}
void	stack_clear(t_stack *stack)
{
	t_node *node;
	t_node *node_aux;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		node_aux = node->next;
		free(node);
		node = node_aux;
	}
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}
void	stack_free(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_clear(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		stack_clear(stack_b);
		free(stack_b);
	}
}