/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 22:57:11 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/11 10:20:18 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/parsing.h"
#include "../includes/stack_utils.h"
#include "../includes/algorithms.h"
#include "debug/debug.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	//t_stack	*stack_b;

	stack_a = stack_new('a');
	if (!stack_a)
		return (1);
	//stack_b = NULL;
	if (argc == 1)
	{
		stack_free(stack_a);
		return (0);
	}
	i = 1;
	while (i < argc && argv[i])
	{
		if (check_flags(argv[i]) == 1)
			i++;
		else
			break;
	}
	if (i == argc)
	{
		stack_free(stack_a);
		return (0);
	}
	if (parse_arguments(argc, argv, i, stack_a) == 1)
	{
		stack_free(stack_a);
		return (1);
	}
	ft_printf ("historia\n");
	/* De momento solo llena la pila, y trata de ordenar si son 3 elementos*/
	ft_printf("Stack A antes: \n");
	stack_print(stack_a);
	if (stack_a->size == 3)
	{
		/* No ordena nada porque hace falta asignar los indices correctos (están todos a 0)*/
		alg_three(stack_a);
	}
	
	ft_printf("\n\nStack A despues: \n");
	stack_print(stack_a);
	/* ----------------------------------------------------------------------------*/
	stack_free(stack_a);
	return (0);
}
