/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 23:09:27 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/25 10:55:25 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/parsing.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = stack_new('a');
	stack_a->fd = -1;
	stack_b = stack_new('b');
	stack_b->fd = -1;
	if (!stack_a || !stack_b)
		return (stack_free(stack_a, stack_b), 1);
	i = 1;
	if (parse_arguments(argc, argv, i, stack_a) == 1)
		return (stack_free(stack_a, stack_b), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		read_input(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	final_check(stack_a, stack_b);
	return (0);
}
