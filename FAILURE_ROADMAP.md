# Fallos de algoritmos

Este documento recoge solo los fallos que dependen de la lógica de ordenación.

## Estado actual del tester

- Los tests básicos, los edge cases, las permutaciones pequeñas exhaustivas y el peor caso ya pasan.
- El problema pendiente principal es el número de operaciones en algunos casos grandes.
- `simple` y `adaptive` superan el límite de operaciones para entradas de 500 elementos.

## Tareas pendientes

- [ ] Reducir el número de operaciones de `simple` en entradas de 500 elementos para que entre en el límite.
- [ ] Reducir el número de operaciones de `adaptive` en entradas de 500 elementos para que entre en el límite.
- [ ] Revisar si el ajuste de operaciones afecta a la corrección en otros tamaños.
- [ ] Repetir el tester completo tras cualquier cambio de algoritmo.

## Lo que ya está cubierto

- [x] Ordenación correcta para 3 y 5 elementos.
- [x] Ordenación correcta para entradas ya ordenadas.
- [x] Ordenación correcta para entradas casi ordenadas y peor desorden.
- [x] Soporte correcto para rangos, entradas inválidas y duplicados.
