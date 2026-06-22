# Fallos de algoritmos

Este documento recoge solo los fallos que dependen de la lógica de ordenación.

## Resumen del tester

- Las entradas pequeñas desordenadas siguen siendo inestables en algunos modos.
- `medium` falla en varios casos válidos sin ordenar completamente la pila.
- `adaptive` también falla en varios casos válidos porque delega en algoritmos internos que todavía no están bien cerrados.
- `simple` ordena en muchos casos, pero en 500 elementos supera el límite de operaciones.
- `radix` parece ser la ruta más consistente, pero no es el foco del siguiente ajuste.

## Fallos detectados

- [ ] `simple` no cumple el límite de operaciones en algunos casos de 500 elementos.
- [ ] `medium` no ordena correctamente varias entradas desordenadas.
- [ ] `adaptive` no ordena correctamente varias entradas desordenadas.
- [ ] Permutaciones pequeñas exhaustivas siguen fallando en algunos modos.
- [ ] Entradas casi ordenadas con una sola inversión todavía fallan en algunos caminos.
- [ ] El caso de peor desorden debe seguir ordenando correctamente en todos los modos.
- [ ] Las entradas con `INT_MIN` y `INT_MAX` deben ordenar correctamente en todos los modos.

## Hipótesis

- El problema principal está en la corrección de la lógica de los algoritmos, no en el parsing.
- `adaptive` no es un algoritmo independiente: los fallos vienen de los algoritmos internos que selecciona.
- `chunk_sort` es el candidato más probable para los fallos de `medium` y parte de `adaptive`.

## Roadmap de corrección

### Fase 1: Reproducir fallos mínimos

- [ ] Repetir un caso fallido de 3 elementos.
- [ ] Repetir un caso fallido de 5 elementos.
- [ ] Repetir un caso fallido de 10 elementos.
- [ ] Anotar qué algoritmo deja la pila sin ordenar.

### Fase 2: Revisar invariantes de pila

- [ ] Comprobar que `push` mantiene `top`, `bot` y `size` coherentes.
- [ ] Comprobar que `swap` no rompe enlaces.
- [ ] Comprobar que `rotate` preserva el final de la lista.
- [ ] Comprobar que `reverse_rotate` preserva la cabecera y la cola.

### Fase 3: Corregir por familias

- [ ] Corregir `insertion_basic`.
- [ ] Corregir `insertion_sort`.
- [ ] Corregir `chunk_sort`.
- [ ] Revisar `adaptive_sort` solo cuando los internos estén estables.

### Fase 4: Validación

- [ ] Repetir el tester completo.
- [ ] Confirmar que ya no hay fallos de ordenación.
- [ ] Revisar después los límites de operaciones.
