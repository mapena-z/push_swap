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

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (init_checker(&stack_a, &stack_b, argc, argv))
		return (1);
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
