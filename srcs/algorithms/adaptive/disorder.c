#include "../includes/push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node *current;
	t_node *compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || stack->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}