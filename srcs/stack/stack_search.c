/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:52 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:18:19 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* Devuelve el nodo que ocupa la posicion dada dentro de la pila. */
t_node	*stack_get_at(t_stack *stack, int index)
{
	t_node	*node;
	int		i;

	if (!stack || index < 0 || index >= stack->size)
		return (NULL);
	node = stack->top;
	i = 0;
	while (node && i < index)
	{
		node = node->next;
		i++;
	}
	return (node);
}

/* Busca la posicion del nodo con el indice mas pequeno de la pila. */
int	stack_min_pos(t_stack *stack)
{
	t_node	*node;
	int		min_index;
	int		min_pos;
	int		pos;

	if (!stack || stack->size == 0)
		return (-1);
	node = stack->top;
	min_index = node->index;
	min_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index < min_index)
		{
			min_index = node->index;
			min_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (min_pos);
}

/* Busca la posicion del nodo con el indice mas grande de la pila. */
int	stack_max_pos(t_stack *stack)
{
	t_node	*node;
	int		max_index;
	int		max_pos;
	int		pos;

	if (!stack || stack->size == 0)
		return (-1);
	node = stack->top;
	max_index = node->index;
	max_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->index > max_index)
		{
			max_index = node->index;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}

/* Devuelve la posicion del primer nodo cuyo indice coincide con el buscado. */
int	stack_find_index(t_stack *stack, int index)
{
	t_node	*node;
	int		pos;

	if (!stack || stack->size == 0)
		return (-1);
	node = stack->top;
	pos = 0;
	while (node)
	{
		if (node->index == index)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

t_node	*stack_find_pos(t_stack *stack, int n)
{
	t_node	*node;
	int		i;

	if (!stack || stack->size == 0 || n < 0)
		return (NULL);
	node = stack->top;
	i = 0;
	while (node)
	{
		if (i == n)
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}
