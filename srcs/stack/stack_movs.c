/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:41:42 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/14 18:58:45 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack_utils.h"
#include "../../includes/operations.h"

/* Rota stack_a en la dirección más corta para llevar una posición concreta al top. */
void	rotate_a_to_pos(t_stack *stack, int pos)
{
	int		count;

	if (!stack  || pos < 0 || pos >= stack->size)
		return ;
	count = 0;
	if (pos <= stack->size / 2)
	{
		while (count < pos)
		{
			ra(stack);
			count ++;
		}
	}else
	{
		while (count < stack->size - pos)
		{
			rra(stack);
			count++;
		}
	}
}

/* Empuja todos los elementos del chunk actual desde a hacia b. */
void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	while (start < end)
	{
		pb(stack_a, stack_b);
		start++;
	}
}

/* Rota stack_b para dejar arriba el lugar correcto donde insertar un nuevo índice. */
void	prepare_b_for_push(t_stack *stack_b, int index)
{
	
}
/*  Encuentra la posición donde debe insertarse index en stack_b manteniendo el orden lógico. */
int	find_insertion_pos(t_stack *stack_b, int index)
{
	
}
/*  Encuentra la posición del mejor candidato para devolver a a, normalmente el máximo de b. */
int	find_best_push_back_pos(t_stack *stack_b)
{
	
}
/*  Devuelve todos los elementos de b a a en el orden correcto. */
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	
}

/*  Sube al top de b el elemento que debe salir primero y lo manda a a.*/
void	push_back_best_element(t_stack *stack_a, t_stack *stack_b);

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	
}