# Chunk Sort - checklist mínimo funcional

## Objetivo
- [ ] Tener los índices normalizados antes de entrar al algoritmo.
- [ ] Dividir `A` en chunks por rango de índices.
- [ ] Pasar todos los elementos de `A` a `B` chunk a chunk.
- [ ] Devolver todos los elementos de `B` a `A` en orden correcto.

## Requisitos mínimos
- [x] `ft_sqrt(int n)` devuelve una base razonable para calcular chunks.
- [x] `get_chunk_size(int n)` define el tamaño del chunk.
- [x] `get_chunk_count(int n)` define cuántos chunks vas a procesar.
- [x] `get_chunk_range(int chunk_id, int chunk_size, int total, int *start, int *end)` calcula el rango actual.
- [x] `stack_has_index_in_range(t_stack *stack, int start, int end)` permite saber si queda algo de ese chunk en `A`.

## Flujo mínimo del algoritmo
- [ ] Si `A` tiene pocos elementos, usar un algoritmo corto en vez de chunk sort.
- [ ] Para cada chunk:
  - [ ] Buscar en `A` un elemento cuyo `index` esté dentro del rango actual.
  - [ ] Rotar `A` con la dirección más corta hasta llevar ese elemento al top.
  - [ ] Hacer `pb` para moverlo a `B`.
  - [ ] Repetir hasta que no queden elementos de ese chunk en `A`.
- [ ] Cuando todos los chunks estén procesados, vaciar `B` hacia `A`.
- [ ] Antes de cada `pa`, elegir el elemento correcto de `B` para mantener el orden global.
- [ ] Terminar cuando `B` esté vacía.

## Versión mínima para que funcione
- [ ] Implementar `chunk_sort(t_stack *stack_a, t_stack *stack_b)` con el bucle principal.
- [ ] Implementar una búsqueda simple del siguiente elemento del chunk en `A`.
- [x] Implementar `rotate_a_to_pos(t_stack *stack, int pos)`.
- [ ] Implementar una estrategia básica para devolver elementos de `B` a `A`.
- [ ] Si no quieres optimizar `B`, puedes usar siempre el máximo de `B` como siguiente salida.

## Funciones en blanco que son optimización, no bloqueo
- [ ] `prepare_b_for_push(t_stack *stack_b, int index)`.
- [ ] `find_insertion_pos(t_stack *stack_b, int index)`.
- [ ] `find_best_push_back_pos(t_stack *stack_b)`.
- [ ] `push_back_to_a(t_stack *stack_a, t_stack *stack_b)`.
- [ ] `push_back_best_element(t_stack *stack_a, t_stack *stack_b)`.

## Cosas ya dibujadas pero todavía incompletas
- [x] `push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)` existe como esqueleto.
- [ ] `chunk_sort(t_stack *stack_a, t_stack *stack_b)` tiene la firma puesta, pero todavía no el flujo real.

## Idea práctica
- [ ] Primero hacerlo funcionar aunque use más movimientos.
- [ ] Después reducir movimientos afinando las rotaciones de `B`.
- [ ] Por último comparar contra `insertion_sort` y `insertion_basic` para ver si merece la pena.
