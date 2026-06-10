/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:57:11 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/10 12:07:41 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc && argv[i])
	{
		if (check_flags(argv[i]) == 1)
			i++;
		else
			break;
	}
	if (i == argc)
		return (0);
	if (parse_arguments(argc, argv, i) == 1)
		return (1);
	ft_printf ("historia\n");
	return (0);
}
