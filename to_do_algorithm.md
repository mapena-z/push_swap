# Push Swap - Stack Search and Info Functions

## Stack Search and Info

### stack_get_at(stack, index)
Obtiene el nodo en una posición específica

t_node *node = stack_get_at(stack_a, 2);
// Obtiene el nodo en posición 2 (tercero desde top)

Usos:
- Verificar qué hay en una posición
- Implementar algoritmos que necesiten acceso por posición
- Debugging

---

### stack_min_pos(stack)
Encuentra la posición del nodo con index mínimo

int pos = stack_min_pos(stack_a);
// Devuelve: 0, 1, 2... (posición del número más pequeño)

Usos:
- Chunk Sort: para encontrar dónde está el siguiente "chunk" que necesitas mover
- Optimizar rotaciones: saber si rotar o reverse_rotar es más corto
- Heurísticas de ordenamiento

Criticidad: NECESARIA

---

### stack_max_pos(stack)
Encuentra la posición del nodo con index máximo

int pos = stack_max_pos(stack_a);
// Devuelve: 0, 1, 2... (posición del número más grande)

Usos:
- Chunk Sort: encontrar límites de chunks
- Validar si algo está ya ordenado
- Optimización de movimientos

Criticidad: Opcional

---

### stack_find_index(stack, index)
Busca un nodo específico por su index

int pos = stack_find_index(stack_a, 5);
// Busca el nodo con index=5 y devuelve su posición

Usos:
- Chunk Sort: "necesito meter el index 7 en B"
- Encontrar dónde está un número específico
- Algoritmos que necesitan referencias cruzadas

Criticidad: NECESARIA

---

## Debug Functions

### stack_print(stack)
Imprime la pila completa (para debugging)

stack_print(stack_a);
// Output:
// Stack A (size: 5):
// [3, idx:2]
// [1, idx:0]
// [4, idx:3]
// [1, idx:0]
// [5, idx:4]

Usos:
- Ver el estado actual de la pila
- Verificar si las operaciones funcionan correctamente
- Debugging durante desarrollo

Criticidad: Muy importante para desarrollo

---

### stack_print_both(a, b)
Imprime ambas pilas lado a lado

stack_print_both(stack_a, stack_b);
// Output:
// Stack A (size: 3)    |    Stack B (size: 2)
// [3, idx:2]           |    [5, idx:4]
// [1, idx:0]           |    [2, idx:1]
// [4, idx:3]           |

Usos:
- Ver estado completo después de una operación
- Verificar transiciones entre pilas
- Debugging de pa/pb

Criticidad: Muy importante para desarrollo

---

## Resumen de Prioridades

Función | Necesaria | Prioridad
stack_get_at | Opcional | Baja
stack_min_pos | SI | CRITICA
stack_max_pos | Opcional | Media
stack_find_index | SI | CRITICA
stack_print | Si (debug) | Importante
stack_print_both | Si (debug) | Importante

---

## Ejemplo Práctico: Chunk Sort

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	chunk_size = (int)sqrt(a->size);
	
	while (a->size > 0)
	{
		min_pos = stack_min_pos(a);  // Encuentra mínimo
		
		// Rotar hasta que el mínimo esté en top
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
		
		pb(a, b);  // Meter en B
		stack_print_both(a, b);  // Ver estado
	}
}

---

## Plan de Implementación

### Fase 1: Críticas (hacer primero)
- stack_min_pos() - necesaria para Chunk Sort
- stack_find_index() - necesaria para algoritmos
- stack_print() - debugging
- stack_print_both() - debugging

### Fase 2: Complementarias (hacer después)
- stack_get_at() - útil pero no crítica
- stack_max_pos() - para optimizaciones

---
