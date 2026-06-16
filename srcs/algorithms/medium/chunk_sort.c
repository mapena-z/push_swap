/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:19 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 13:42:47 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"
/*
** Mueve stack_a hasta que el elemento situado en `pos` quede en el top.
**
** La idea es usar siempre el camino más corto:
** - si el objetivo está en la mitad superior, hacemos `ra`
** - si está en la mitad inferior, hacemos `rra`
**
** Así evitamos rotaciones innecesarias antes de hacer `pb`.
*/
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
	while (start < end)
	{
		pb(stack_a, stack_b);
		start++;
	}
}

/*
** Prepara B antes de insertar un índice nuevo.
**
** La idea es girar B para que, tras hacer `pb`, el elemento quede colocado
** en una zona coherente con el orden que queremos mantener dentro de B.
** Esta parte sirve para reducir movimientos al reconstruir A después.
*/
void	prepare_b_for_push(t_stack *stack_b, int index)
{
	
}

/*
** Busca la posición lógica de inserción de `index` dentro de B.
**
** Esta función no solo mira dónde cabría el número, sino dónde conviene
** colocarlo para que la pila B siga siendo útil al devolver elementos a A.
*/
int	find_insertion_pos(t_stack *stack_b, int index)
{
	
}

/*
** Elige qué posición de B deberíamos subir primero para devolverla a A.
**
** En una estrategia simple, lo normal es sacar siempre el máximo de B,
** porque así A se reconstruye de forma ordenada con el menor razonamiento.
*/
int	find_best_push_back_pos(t_stack *stack_b)
{
	
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
	
}

/*
** Sube al top de B el elemento que debe salir primero y lo manda a A.
**
** Esta helper sería la versión atómica del paso anterior: elegir, rotar y
** ejecutar `pa` en una sola operación de alto nivel.
*/
void	push_back_best_element(t_stack *stack_a, t_stack *stack_b);

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	
}