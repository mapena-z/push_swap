# Revisión de chunk_sort.c — issues y sugerencias de arreglo

Resumen breve:
- El fichero compila y no presenta errores sintácticos.
- Hay problemas lógicos que impiden que `chunk_sort` procese todos los elementos en algunos casos.

Problemas detectados y propuestas (no aplicadas):

1) Cálculo de `chunk_count` (bug funcional)
- Problema: `chunk_size = get_chunk_size(total)` y `chunk_count = get_chunk_count(total)` usan ambas `ft_sqrt(total)`. Con esta definición `chunk_count * chunk_size` puede ser menor que `total`. Ejemplo: total = 10 => sqrt = 3 => cubre sólo 9 índices (0..8), queda 9 sin procesar.
- Efecto: algunos índices pueden quedarse en `A` y no pasarse a `B`, por lo que `push_back_to_a` no restaurará todo correctamente.
- Soluciones posibles (elige una):
  a) Calcular `chunk_count` correctamente en `chunk_sort` con división entera hacia arriba:

     chunk_size = get_chunk_size(total);
     chunk_count = (total + chunk_size - 1) / chunk_size; /* ceil */

  b) Cambiar `get_chunk_count(int n)` en `chunk_sort_utils.c` para que devuelva `ceil(n / chunk_size)` (necesitaría recibir chunk_size o recomputarlo).

  Recomiendo (a) porque es la corrección local más simple dentro de `chunk_sort.c`.

2) Cobertura de índices en `get_chunk_range`
- Problema: `get_chunk_range` calcula `start = chunk_id * chunk_size; end = start + chunk_size - 1;` pero no garantiza que el último chunk cubra hasta `total - 1` si el cálculo del número de chunks es incorrecto.
- Solución: después de calcular `start`/`end` en `chunk_sort`, forzar `if (end >= total) end = total - 1;` (ya se hace), y con la corrección (1) esto quedará coherente.

3) `prepare_b_for_push` ignora el parámetro `index`
- Estado actual: siempre rota `B` hasta su `max_pos`. No es crítico (versión mínima), pero el comentario sugiere usar `index` para decidir la rotación.
- Mejora opcional: implementar `find_insertion_pos` para devolver la posición adecuada y usarla en `prepare_b_for_push`.

4) `find_insertion_pos` y `find_best_push_back_pos` son placeholders
- Estado actual: devuelven `stack_max_pos(stack_b)` siempre. Funciona como versión mínima (sacar siempre el máximo), pero limita optimizaciones y podría aumentar movimientos.
- Si quieres optimizar, implementar la lógica vista en `insertion_sort.c::find_insertion_pos` (comparar contra min/max y enlaces consecutivos).

5) `push_back_best_element` está implementada y correcta para la estrategia "sacar el máximo".
- Está bien como helper atómico.

6) Casos pequeños (`total <= 5`)
- El fichero decide no actuar para `total <= 5` (delega en otras estrategias). Asegúrate de que el llamador realmente elija la estrategia adecuada cuando `total <= 5`.

7) Limpieza y advertencias
- No hay variables sin usar ahora en el archivo (la versión actual ya eliminó `min_index` no usado).
- Prepárate a compilar con `-Wall -Wextra -Werror` para detectar otras advertencias que podrían aparecer en el build global.

Pruebas sugeridas (manual rápido):
- Compilar el proyecto:

  make

- Probar con entradas de distintos tamaños, por ejemplo:

  ./push_swap 3 2 1 0 4 5 6 7 8 9
  ./push_swap 10 9 8 7 6 5 4 3 2 1 0
  ./push_swap 1 2 3

- Comprobar que todos los elementos acaban en `A` ordenados y que no quedan en `B`.

Resumen de acción prioritaria:
- Cambiar el cálculo de `chunk_count` (ver punto 1). Esa corrección es necesaria para que `chunk_sort` cubra todos los índices.

Si quieres, aplico la corrección local (a): reemplazar la línea que asigna `chunk_count` en `chunk_sort.c` por la versión con `ceil`.
