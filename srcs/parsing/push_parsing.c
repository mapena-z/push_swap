/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_carl_propuesta.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:29:07 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/28 13:38:01 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/stack_utils.h"

void	free_words(char **words)
{
	int	i;

	if (!words)
		return ;
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return (1);
	new_node = node_new(value, 0);
	if (!new_node)
		return (1);
	stack_add_back(stack, new_node);
	return (0);
}

int	is_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
