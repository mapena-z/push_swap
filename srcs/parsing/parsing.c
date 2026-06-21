/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:43:05 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/21 21:32:36 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	stack_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		count;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		count = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = compare->next;
		}
		current->index = count;
		current = current->next;
	}
}

int	check_flags(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0 || ft_strncmp(arg, "--medium",
			9) == 0 || ft_strncmp(arg, "--complex", 10) == 0 || ft_strncmp(arg,
			"--adaptive", 11) == 0 || ft_strncmp(arg, "--bench", 8) == 0)
	{
		return (1);
	}
	return (0);
}

int	check_split(char *argv, t_stack *stack)
{
	char	**numbers;
	int		i;
	long	value;

	if (!argv || *argv == '\0' || (argv[0] == ' ' && ft_strlen(argv) == 1))
		return (1);
	numbers = ft_split(argv, ' ');
	if (!numbers)
		return (1);
	i = 0;
	while (numbers[i] != NULL)
	{
		value = ft_atol(numbers[i]);
		if (!check_long(value) || !is_number(numbers[i]))
			return (free_words(numbers), 1);
		ft_push(stack, value);
		if (is_duplicate(stack))
			return (free_words(numbers), 1);
		i++;
	}
	free_words(numbers);
	return (0);
}

int	parse_arguments(int argc, char **argv, int i, t_stack *stack)
{
	while (i < argc)
	{
		if (check_split(argv[i], stack))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
