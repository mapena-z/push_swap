/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:55 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/14 17:41:56 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	stack->fd = 1;
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
void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	stack_clear(stack);
	free(stack);
}