/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_nd_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:58 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:19:37 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*node_new(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = index;
	node->next = NULL;
	node->value = value;
	return (node);
}

void	stack_add_front(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	if (stack->size == 0)
		stack->bot = node;
	stack->size++;
}

void	stack_add_back(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bot = node;
	}
	else
	{
		stack->bot->next = node;
		stack->bot = node;
	}
	stack->size++;
}
