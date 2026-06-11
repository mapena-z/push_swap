/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 11:43:05 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/11 10:38:05 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_flags(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0 || ft_strncmp(arg, "--medium", 9) == 0
		|| ft_strncmp(arg, "--complex", 10) == 0
		|| ft_strncmp(arg, "--adaptive", 11) == 0
		|| ft_strncmp(arg, "--bench", 8) == 0)
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
	i = 0;
	if (numbers != NULL)
	{
		while (numbers[i] != NULL)
		{
			value = ft_atol(numbers[i]);
			if (!check_long(value) || !is_number(numbers[i]))
				return (1);
			push(stack, value);
			i++;
		}
	}
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
