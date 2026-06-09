#include "../../includes/push_swap.h"

t_node	*stack_get_at(t_stack *stack, int index)
{
	t_node *node;
	int i;

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

int	stack_min_pos(t_stack *stack)
{
	t_node *node;
	int min_index;
	int min_pos;
	int pos;

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

int	stack_max_pos(t_stack *stack)
{
	t_node *node;
	int max_index;
	int max_pos;
	int pos;

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

int	stack_find_index(t_stack *stack, int index)
{
	t_node *node;
	int pos;

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