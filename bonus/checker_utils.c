/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 23:10:38 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/16 23:11:07 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker_error(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line)
		free(line);
	stack_free(stack_a);
	stack_free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top || stack->size <= 1)
		return (1);
	node = stack->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	final_check(t_stack *stack_a, t_stack *stack_b)
{
	if (is_stack_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(stack_a);
	stack_free(stack_b);
}

void	read_input(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else
		checker_error(stack_a, stack_b, line);
}
