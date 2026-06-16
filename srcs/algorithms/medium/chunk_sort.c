/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:19 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 15:52:48 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
#include "../../../includes/algorithms.h"
/*
** Mueve stack_a hasta que el elemento situado en `pos` quede en el top.
**
** La idea es usar siempre el camino más corto:
** - si el objetivo está en la mitad superior, hacemos `ra`
** - si está en la mitad inferior, hacemos `rra`
**
** Así evitamos rotaciones innecesarias antes de hacer `pb`.
*/

/*
** Prepara B antes de insertar un índice nuevo.
**
** La idea es girar B para que, tras hacer `pb`, el elemento quede colocado
** en una zona coherente con el orden que queremos mantener dentro de B.
** Esta parte sirve para reducir movimientos al reconstruir A después.
*/
void	prepare_b_for_push(t_stack *stack_b, int index)
{
	int max_index;

	max_index = stack_max_pos(stack_b);
	rotate_pos_to_top(stack_b, max_index);
}

/*
** Busca la posición lógica de inserción de `index` dentro de B.
**
** Esta función no solo mira dónde cabría el número, sino dónde conviene
** colocarlo para que la pila B siga siendo útil al devolver elementos a A.
*/
int	find_insertion_pos(t_stack *stack_b, int index)
{
	return stack_max_pos(stack_b);
}

/*
** Elige qué posición de B deberíamos subir primero para devolverla a A.
**
** En una estrategia simple, lo normal es sacar siempre el máximo de B,
** porque así A se reconstruye de forma ordenada con el menor razonamiento.
*/
int	find_best_push_back_pos(t_stack *stack_b)
{
	return (stack_max_pos(stack_b));
}

/*
** Vacía B hacia A respetando el orden final.
**
** La lógica esperada es:
** - escoger el candidato correcto en B
** - rotar B para llevarlo al top
** - hacer `pa`
** - repetir hasta dejar B vacía
*/
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		rotate_pos_to_top(stack_b, find_best_push_back_pos(stack_b));
		pa(stack_a, stack_b);
	}
}

void	rotate_pos_to_top(t_stack *stack, int pos)
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

/*
** Versión base del traslado de un chunk desde A a B.
**
** En una implementación completa, aquí no se empujan elementos al azar:
** primero se busca dentro de A un `index` que pertenezca al rango del chunk,
** luego se rota A hasta dejarlo arriba y finalmente se hace `pb`.
**
** Ahora mismo esta función solo representa la intención del bloque.
*/
void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int pos;
	t_node *node;

	if (!stack_a || !stack_b)
		return ;
	/* Mientras queden elementos del rango en A */
	while (stack_has_index_in_range(stack_a, start, end) == 1)
	{
		/* Buscar la primera posición en A cuyo index esté en [start,end] */
		node = stack_a->top;
		pos = 0;
		while (node && !(node->index >= start && node->index <= end))
		{
			node = node->next;
			pos++;
		}
		if (!node)
			break ;
		/* Llevarla al top y empujar a B */
		rotate_pos_to_top(stack_a, pos);
		prepare_b_for_push(stack_b, stack_a->top->index);
		pb(stack_a, stack_b);
	}
}



/*
** Sube al top de B el elemento que debe salir primero y lo manda a A.
**
** Esta helper sería la versión atómica del paso anterior: elegir, rotar y
** ejecutar `pa` en una sola operación de alto nivel.
*/

void	push_back_best_element(t_stack *stack_a, t_stack *stack_b)
{
	int pos;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	pos = find_best_push_back_pos(stack_b);
	rotate_pos_to_top(stack_b, pos);
	pa(stack_a, stack_b);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int total;
	int chunk_size;
	int chunk_count;
	int chunk_id;
	int start;
	int end;

	if (!stack_a || !stack_b)
		return ;
	total = stack_a->size;
	if (total <= 5)
	{
		/* Dejar que otras estrategias manejen casos pequeños */
		return ;
	}
	chunk_size = get_chunk_size(total);
	/* asegurar que cubrimos todos los elementos: ceil(total / chunk_size) */
	if (chunk_size <= 0)
		chunk_size = 1;
	chunk_count = (total + chunk_size - 1) / chunk_size;
	chunk_id = 0;
	while (chunk_id < chunk_count)
	{
		get_chunk_range(chunk_id, chunk_size, total, &start, &end);
		if (end >= total)
			end = total - 1;
		push_chunk_to_b(stack_a, stack_b, start, end);
		chunk_id++;
	}
	/* Una vez todos los elementos están en B según chunks, devolverlos a A */
	push_back_to_a(stack_a, stack_b);
}