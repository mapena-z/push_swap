# Turk Sort (algoritmo simple)

**Archivos:** `turk_sort.c`, `turk_sort_utils.c`, `turk_sort_aux.c`  
**Flag:** `--simple`  
**Complejidad teórica:** O(n²)  
**Objetivo de rendimiento:** < 5500 operaciones con 500 elementos

Basado en el **Turk algorithm** (variante de insertion sort optimizada para push_swap): en cada paso empuja a B el elemento de A con **menor coste total** de rotación, manteniendo B en orden descendente circular.

---

## Estructura de datos auxiliar

```c
typedef struct s_move {
    int pos_a;   // posición del nodo en A
    int pos_b;   // posición de inserción en B
    int cost;    // coste total de rotaciones
} t_move;
```

---

## Fases de `turk_sort`

```mermaid
flowchart LR
    P1[Fase 1: A → B] --> P2[Fase 2: B → A]
    P2 --> P3[Fase 3: rotar mínimo al tope]
```

### Fase 1 — Vaciar A hacia B

```c
pb(a, b);  // seed: 2 elementos iniciales en B
pb(a, b);
while (a->size > 0) {
    best = find_cheapest(a, b);
    rotate_both_to_top(a, b, best.pos_a, best.pos_b);
    pb(a, b);
}
```

El **seed de 2 `pb`** da a B estructura suficiente para calcular posiciones de inserción desde el primer ciclo completo.

### Fase 2 — `restore_b_to_a`

Mientras B no esté vacío:

1. `pos = stack_max_pos(b)` — mayor índice en B.
2. `rotate_pos_to_top(b, pos)` — camino corto al tope.
3. `pa(a, b)`.

Al sacar siempre el máximo, A queda en orden ascendente.

### Fase 3 — `rotate_min_to_top_a`

`bring_index_to_top(a, 0)` deja el mínimo global en el tope (formato final esperado).

---

## Cálculo de costes (`turk_sort_utils.c`)

### `moves_to_top(stack, pos)`

| Condición | Movimientos | Operaciones |
|-----------|-------------|-------------|
| `pos <= size/2` | `pos` | `ra` / `rb` |
| `pos > size/2` | `size - pos` | `rra` / `rrb` |

### `compute_cost(a, b, pos_a, pos_b)`

```
cost_a = moves_to_top(A, pos_a)
cost_b = moves_to_top(B, pos_b)
```

Si ambas pilas rotan en la **misma dirección** (ambas forward o ambas backward):

```
cost = max(cost_a, cost_b)   // se pueden usar rr / rrr
```

Si rotan en direcciones opuestas:

```
cost = cost_a + cost_b
```

Esta es la optimización principal frente a un insertion sort ingenuo.

### `find_insert_pos_b(b, target_index)`

B se mantiene en orden **descendente circular** por índice:

- Busca un par `(current, next)` donde `current.index > target > next.index` → insertar en `pos + 1`.
- Si `target` es mayor que todos o menor que todos → insertar sobre `max_pos` (posición del índice máximo actual).

### `find_cheapest(a, b)`

Recorre todos los nodos de A, calcula `(pos_a, pos_b, cost)` para cada uno y devuelve el de **menor coste**.

---

## Rotación sincronizada (`turk_sort_aux.c`)

### `rotate_both_to_top(a, b, pos_a, pos_b)`

1. Convierte posiciones a contadores de movimientos (forward o backward).
2. Si ambas forward → `rr_pos` hasta agotar el mínimo de los dos contadores.
3. Si ambas backward → `rrr_pos` igual.
4. Termina con `rotate_stack_a` y `rotate_stack_b` los movimientos restantes.

### `rr_pos` / `rrr_pos`

Bucles que ejecutan `rr` o `rrr` mientras ambos contadores > 0, decrementando en paralelo.

---

## Cuándo brilla este algoritmo

| Escenario | Rendimiento |
|-----------|-------------|
| Bajo desorden (15–20 %) | Mejor opción del proyecto |
| n ≈ 100, desorden medio | Competitivo, a veces gana a chunk |
| n = 500, desorden alto | Superado por radix/chunk |

Activado con `--simple` o por `adaptive_sort` cuando `disorder < 0.2`.

---

## Dependencias externas

| Función | Origen |
|---------|--------|
| `rotate_pos_to_top` | `medium/chunk_sort.c` |
| `bring_index_to_top` | `short/short_utils.c` |
| `stack_max_pos`, `stack_find_index` | `stack/stack_search.c` |
| `pb`, `pa`, `ra`, `rra`, `rr`, `rrr` | `operations/` |