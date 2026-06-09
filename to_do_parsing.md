## ¿Qué es `index`?

**NO es la posición en la pila.**

`index` es el **rango del número ordenado**: va de `0` a `n - 1`.

### Ejemplo
Input: `3 1 4 2 5`
Ordenado: `1 2 3 4 5`

Asignación de índices:
- `1` → index `0`
- `2` → index `1`
- `3` → index `2`
- `4` → index `3`
- `5` → index `4`

## ¿Cuándo se asigna?

**Solo en el parsing**, una sola vez. Después **no cambia nunca**.

## ¿Por qué usar `index`?

- Evita depender de valores grandes o negativos
- Los algoritmos comparan por `index`, no por `value`
- Simplifica mucho el ordenamiento

## Estructura base

```c
typedef struct s_node
{
    int             value;   // Número original
    int             index;    // Rango ordenado (0 a n-1) - no cambia
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;             // Primer nodo
    t_node  *tail;            // Último nodo
    int     size;
    char    name;             // 'a' o 'b'
}   t_stack;
```