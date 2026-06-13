#include "../includes/push_swap.h"

/*
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
*/

int	compute_disorder(t_stack *stack)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			total_pairs++;
			if ()
			{

			}
			
		}
		i++;
	}
	

}