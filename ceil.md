# `ceil` explicado

`ceil` viene de *ceiling* y significa **redondear hacia arriba**.

Si tienes un número real, `ceil(x)` devuelve el **menor entero mayor o igual que `x`**.

## Definición

Para cualquier número `x`:

- si `x` ya es entero, `ceil(x) = x`
- si `x` tiene parte decimal, `ceil(x)` sube al siguiente entero

## Ejemplos

- `ceil(3.0) = 3`
- `ceil(3.1) = 4`
- `ceil(3.9) = 4`
- `ceil(0.2) = 1`
- `ceil(-1.2) = -1`

## Para qué sirve en `push_swap`

En el algoritmo de chunks se quiere calcular cuántos grupos hacen falta para cubrir todos los elementos.

La idea es esta:

```c
chunk_count = ceil(total / chunk_size);
```

Si `total` no es múltiplo exacto de `chunk_size`, el último chunk queda incompleto, pero igual cuenta como un chunk más.

### Ejemplo

Si tienes `total = 10` elementos y `chunk_size = 3`:

- `10 / 3 = 3.333...`
- `ceil(3.333...) = 4`

Entonces necesitas 4 chunks:

- chunk 1: 3 elementos
- chunk 2: 3 elementos
- chunk 3: 3 elementos
- chunk 4: 1 elemento

## Cómo se emula `ceil` con enteros

En C, si usas enteros, `10 / 3` da `3`, no `3.333...`, porque la división entera corta la parte decimal.

Por eso se usa esta fórmula:

```c
(n + d - 1) / d
```

Donde:

- `n` es el total
- `d` es el tamaño del chunk

### Por qué funciona

Si `n` es múltiplo de `d`, la fórmula devuelve el resultado exacto.

Si `n` no es múltiplo de `d`, sumar `d - 1` empuja el resultado hacia el siguiente entero cuando la división se hace con enteros.

### Ejemplos

- `(10 + 3 - 1) / 3 = 12 / 3 = 4`
- `(9 + 3 - 1) / 3 = 11 / 3 = 3`
- `(8 + 5 - 1) / 5 = 12 / 5 = 2`

## Ojo con el divisor

Esta fórmula solo funciona si `d > 0`.

Si `d = 0`, hay una división por cero y el programa se rompe.

Por eso, antes de usarla, hay que garantizar que `chunk_size` nunca sea 0.

## Relación con tu código

En `chunk_sort_utils.c` aparece este comentario:

```c
chunk_count = (n + chunk_size - 1) / chunk_size; /* ceil */
```

Eso significa que esa expresión está simulando `ceil(n / chunk_size)` usando solo enteros.

En otras palabras, el comentario `/* ceil */` quiere decir:

- “aquí no estamos haciendo una división normal con decimales”
- “estamos calculando el número mínimo de chunks necesarios, redondeando hacia arriba”

## Resumen corto

`ceil` = redondear hacia arriba.

En chunks, sirve para no perder los elementos que sobran cuando el total no se divide exacto.

La fórmula entera equivalente es:

```c
(n + d - 1) / d
```
