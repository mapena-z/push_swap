## ¿Qué es `index`?

**NO es la posición en la pila.**

`index` es el **rango del número ordenado** (0 a n-1).

### Ejemplo
Input: `3 1 4 1 5`
Ordenado: `1 1 3 4 5`

- `3` → index `2`
- `1` → index `0`
- `4` → index `3`
- `1` → index `0`
- `5` → index `4`

## ¿Cuándo se asigna?

**Solo en el parsing**, una sola vez. Después **NUNCA cambia**.

## ¿Por qué?

- Evitas números negativos o muy grandes
- Los algoritmos comparan por `index`, no por `value`
- Simplifica el código

## Estructura Base

```c
typedef struct s_node {
    int value;              // Número original
    int index;              // Rango (0 a n-1) - NUNCA CAMBIA
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;            // Primer nodo
    t_node *tail;           // Último nodo
    int size;
    char name;              // 'a' o 'b'
} t_stack;
```