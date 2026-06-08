#include "../../includes/push_swap.h"
#include "stack.h"

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
		return (NULL);
	stack_clear(stack);
	free(stack);
}