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

void	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = node_new(value, 0);
	if (!new_node)
		return ;
	stack_add_back(stack, new_node);
}
