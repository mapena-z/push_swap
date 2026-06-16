/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:01:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/16 13:44:46 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"
#include "../../../includes/stack_utils.h"

/*
	Antes de entrar en chunk sort, los valores ya deben estar normalizados.

	La normalización convierte el número más pequeño en index = 0, el siguiente
	en index = 1 y así sucesivamente hasta el mayor, que queda en n - 1.

	Con eso, trabajar por rangos es mucho más simple porque ya no importa el
	valor real del número, solo su posición relativa dentro del conjunto.
*/
/*
	Devuelve la parte entera de la raíz cuadrada de n.

	En esta estrategia se usa como una base rápida para dividir la entrada en
	chunks de tamaño aproximado sqrt(n). No busca ser perfecta, solo dar una
	referencia estable para repartir el trabajo.
*/
int	ft_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

/*
	Calcula el tamaño de cada chunk.

	Aquí se reutiliza ft_sqrt(n) porque una división en bloques de ese orden
	suele dar un compromiso razonable entre simplicidad y número de movimientos.
*/
int	get_chunk_size(int n)
{
	return (ft_sqrt(n));
}

/*
	Calcula cuántos chunks se van a procesar.

	Si n es menor o igual que cero, no hay nada que dividir. En caso contrario,
	se usa la misma referencia sqrt(n) para mantener el reparto coherente.
*/
int	get_chunk_count(int n)
{
	int	count;

	if (n <= 0)
		return (0);
	count = ft_sqrt(n);
	if (count < 1)
		count = 1;
	return (count);
}

/*
	Devuelve el rango de índices correspondiente a un chunk concreto.

	Cada chunk ocupa un bloque consecutivo de índices. start marca el primer
	índice del bloque y end el último. El parámetro total está aquí por firma,
	pero en esta versión no se usa todavía para ajustar el último chunk.
*/
void	get_chunk_range(int chunk_id, int chunk_size, int total, int *start, int *end)
{
	*start = chunk_id * chunk_size;
	*end = *start + chunk_size - 1;
}

/*
	Comprueba si un índice pertenece al rango [start, end].

	Se mantiene como helper pequeño porque la comprobación de rango se repite
	muchas veces al recorrer la pila buscando elementos del chunk actual.
*/
int	index_in_range(int index, int start, int end)
{
	return (index >= start && index <= end);
}

/*
	Recorre la pila buscando si todavía queda al menos un elemento dentro del
	rango actual del chunk.

	Devuelve:
	- 1 si encuentra algún index dentro del rango
	- 0 si no hay ninguno
	- -1 si la pila no es válida o el rango es incoherente

	Esta función sirve para saber cuándo terminar el procesamiento del chunk sin
	tener que recorrer A más de la cuenta.
*/
int	stack_has_index_in_range(t_stack *stack, int start, int end)
{
	t_node *node;

	if (!stack || start > end)
		return (-1);
	node = stack->top;
	while (node)
	{
		if (index_in_range(node->index, start, end))
			return (1);
		node = node->next;
	}
	return (0);
}