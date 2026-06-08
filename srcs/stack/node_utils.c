#include "../../includes/push_swap.h"

t_node	*node_new(int value, int index)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = index;
	node->next = NULL;
	node->value = value;
	return (node);
}

void	node_free(t_node *node)
{
	if (node)
		free(node);
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
		return;

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