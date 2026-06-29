# Informe de auditoría — push_swap

**Fecha:** 29 de junio de 2026  
**Alcance:** análisis estático, norminette, valgrind, pruebas funcionales y corrección de hallazgos.

---

## Resumen ejecutivo

Se analizó el proyecto completo (`push_swap`, `checker`, `libft`). Se encontraron **bugs de parsing**, **código muerto**, **incoherencias de norma 42** y **riesgos de memoria**. Tras las correcciones:

- Compilación con `-Wall -Wextra -Werror`: OK
- Norminette (`srcs/`, `includes/`, `bonus/`): OK
- Valgrind (sin leaks en rutas normales y `--bench`): OK

---

## 1. Bugs corregidos

### 1.1 Error silencioso sin argumentos numéricos

**Problema:** `./push_swap --simple` devolvía `exit 1` sin imprimir `Error\n`.

**Causa:** `init_and_parse()` retornaba error cuando `first_value_arg() == argc`, pero no escribía en stderr.

**Corrección:** Se añadió `write(2, "Error\n", 6)` en ese caso (`parsing.c`).

---

### 1.2 Checker no ignoraba flags

**Problema:** `./checker --simple 3 2 1` fallaba porque el checker parseaba `--simple` como número.

**Causa:** `main_checker.c` llamaba a `parse_arguments()` desde el índice 1, sin saltar flags.

**Corrección:**
- Nueva función `init_checker()` en `checker_utils.c` que usa `validate_flags()` y `first_value_arg()`.
- `main_checker.c` simplificado para delegar la inicialización.

---

### 1.3 Overflow en `ft_atol`

**Problema:** Cadenas numéricas enormes podían desbordar `long` y, en casos extremos, producir valores dentro del rango `int` tras el wrap-around, pasando la validación.

**Causa:** No había comprobación de overflow antes de `result * 10 + digit`.

**Corrección:** Detección de overflow en `validation.c`; en overflow se devuelve `LONG_MAX`, que `check_long()` rechaza al exceder `INT_MAX`.

---

### 1.4 Fallo silencioso de `malloc` en `ft_push`

**Problema:** Si `node_new()` fallaba, `ft_push()` retornaba sin error y el parsing continuaba con datos incompletos.

**Corrección:** `ft_push()` ahora retorna `int` (0 = OK, 1 = error). `check_split()` propaga el fallo y libera recursos.

---

### 1.5 Gestión de memoria del benchmark

**Problema:** `stack_free()` liberaba pilas y nodos, pero no el struct `t_benchmark` compartido entre `stack_a` y `stack_b`. La liberación estaba solo en `main.c`.

**Corrección:** `stack_free()` libera `bench` desde `stack_a` y anula el puntero en `stack_b` para evitar double-free.

---

### 1.6 Campo `fd` sin inicializar

**Problema:** `stack_new()` no inicializaba `fd`. Dependía de llamadas posteriores a `set_fd()`.

**Corrección:** `stack_new()` inicializa `fd = 1` por defecto.

---

## 2. Código muerto eliminado

### 2.1 Archivos comentados al 100 % (eliminados)

| Archivo | Motivo |
|---------|--------|
| `srcs/parsing/push_mpena_orig.c` | Versión antigua comentada, no compilada |
| `srcs/main_alg_test.c` | Test manual comentado, no compilado |
| `srcs/debug/debug.c` | Debug comentado, no compilado |
| `srcs/debug/debug.h` | Header de debug comentado |

### 2.2 Funciones declaradas pero nunca usadas (eliminadas)

| Función | Archivo original |
|---------|------------------|
| `stack_find_pos()` | `stack_search.c` / `stack_utils.h` |
| `prepare_b_for_push()` | `chunk_sort_utils.c` / `algorithms.h` |
| `ft_pos_of_index()` | `chunk_sort.c` |

---

## 3. Incoherencias y norma 42 corregidas

| Hallazgo | Corrección |
|----------|------------|
| Declaración duplicada de `moves_to_top` en `algorithms.h` | Eliminada la duplicata |
| Comentario `// Utils` en header (prohibido por norma) | Eliminado |
| Comentario en español en `benchmark.h` | Eliminado |
| `check_flags()` duplicaba lógica de `is_algo_flag` / `is_extra_flag` | `check_flags()` reimplementado reutilizando esas funciones |
| Include incorrecto en `disorder.c` (`../includes/...`) | Corregido a `../../../includes/push_swap.h` |
| `check_long()` usaba literales mágicos | Sustituidos por `INT_MIN` / `INT_MAX` |
| `TOO_MANY_FUNCS` en `validation.c` y `parsing_utils.c` | Reorganización: `is_duplicate` → `push_carl_propuesta.c`, `check_flags` → `parsing.c` |
| `TOO_MANY_LINES` en `ft_atol` y `main_checker` | `ft_atol` compactado; lógica del checker extraída a `init_checker()` |

---

## 4. Análisis de memoria (Valgrind)

| Escenario | Resultado |
|-----------|-----------|
| `./push_swap 5 4 3 2 1` | 0 leaks |
| `./push_swap --bench 5 4 3 2 1` | 0 leaks |
| `./push_swap 5 4 3 2 1 \| ./checker 5 4 3 2 1` | 0 leaks, `OK` |

No se detectaron segfaults ni invalid reads/writes en las rutas probadas.

---

## 5. Hallazgos no corregidos (fuera de alcance o aceptables)

### 5.1 Rendimiento en casos grandes

En pruebas aleatorias de 500 elementos, algún caso superó 7000 operaciones (~7435). Es un tema de **optimización algorítmica**, no de corrección funcional ni de memoria. Los algoritmos (`turk_sort`, `chunk_sort`, `radix`, `adaptive`) funcionan correctamente.

### 5.2 Comentarios en bloque extensos en `radix.c` y `turk_sort.c`

Norminette los acepta. Son documentación interna del algoritmo; no se modificaron para no ampliar el diff.

### 5.3 Comentarios en español en `stack_search.c`

Norminette OK. Son comentarios descriptivos válidos bajo la norma (`/* */`).

---

## 6. Archivos modificados

```
bonus/checker_utils.c
bonus/main_checker.c
includes/algorithms.h
includes/benchmark.h
includes/checker.h
includes/parsing.h
includes/stack_utils.h
srcs/algorithms/adaptive/disorder.c
srcs/algorithms/medium/chunk_sort.c
srcs/algorithms/medium/chunk_sort_utils.c
srcs/main.c
srcs/parsing/parsing.c
srcs/parsing/parsing_utils.c
srcs/parsing/push_carl_propuesta.c
srcs/parsing/validation.c
srcs/stack/stack_search.c
srcs/stack/stack_utils.c
```

## 7. Archivos eliminados

```
srcs/debug/debug.c
srcs/debug/debug.h
srcs/main_alg_test.c
srcs/parsing/push_mpena_orig.c
```

---

## 8. Verificación final

```bash
make re && make checker
norminette srcs includes bonus
valgrind --leak-check=full ./push_swap 5 4 3 2 1
./push_swap --simple          # debe imprimir Error y exit 1
./push_swap --simple 3 2 1 | ./checker --simple 3 2 1  # debe imprimir OK
```

Todos los comandos anteriores pasan correctamente tras las correcciones.