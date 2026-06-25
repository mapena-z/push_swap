/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:18:42 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/25 11:18:55 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/push_swap.h"
//#include "../includes/stack_utils.h"
//#include "../includes/algorithms.h"
//#include "debug/debug.h"
//#include <stdlib.h>
//#include <time.h>

//static void	create_random_stack(t_stack *stack, int count)
//{
//	int	i;
//	int	val;
//	t_node	*node;
//	t_node	*cur;
//	int	unique;

//	srand((unsigned)time(NULL));
//	i = 0;
//	while (i < count)
//	{
//		val = (rand() % 2001) - 1000; /* range -1000..1000 */
//		unique = 1;
//		cur = stack->top;
//		while (cur)
//		{
//			if (cur->value == val)
//			{
//				unique = 0;
//				break;
//			}
//			cur = cur->next;
//		}
//		if (!unique)
//			continue;
//		node = node_new(val, 0);
//		stack_add_back(stack, node);
//		i++;
//	}
//}

//static int	assign_indices(t_stack *stack)
//{
//	t_node	*current;
//	t_node	*other;

//	if (!stack)
//		return (1);
//	current = stack->top;
//	while (current)
//	{
//		current->index = 0;
//		other = stack->top;
//		while (other)
//		{
//			if (current != other && current->value == other->value)
//				return (1);
//			if (other->value < current->value)
//				current->index++;
//			other = other->next;
//		}
//		current = current->next;
//	}
//	return (0);
//}

//int	main(void)
//{
//	t_stack	*stack_a;
//	t_stack	*stack_b;

//	stack_a = stack_new('a');
//	stack_b = stack_new('b');
//	create_random_stack(stack_a, 40);
//	assign_indices(stack_a);
//	/* Introducir algoritmo*/

//	//alg_three(stack_a);
//	stack_print(stack_a);
//	//chunk_sort(stack_a, stack_b);
//	//insertion_sort(stack_a, stack_b);
//	//insertion_basic(stack_a, stack_b);
//	radix(stack_a, stack_b);
//	stack_print(stack_a);
//	/* ------------------------------- */
//	free(stack_a);
//	free(stack_b);
//	return (0);
//}
