# pila.md

Documento corto para alinear el criterio entre parsing y movimientos.

La idea es que aquí quede claro:

- cómo entra el input
- cómo se rellena la pila
- cómo se mueven los nodos
- cuándo consideramos que ya está ordenada

## 1. Qué representa la pila

En este proyecto la pila está formada por nodos simples:

```c
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}   t_node;
```

- `value` es el número original que llega por argumento.
- `index` es la posición de ese valor dentro del conjunto ordenado.
- `next` enlaza con el siguiente nodo.

La pila completa se guarda así:

```c
typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	char	name;
}   t_stack;
```

- `top` apunta al primer nodo.
- `bot` apunta al último.
- `size` dice cuántos nodos hay.
- `name` identifica la pila, normalmente `a` o `b`.

## 2. Cómo se interpreta el input

El input entra como argumentos del programa. Primero se validan los flags y después se procesan los números.

Funciones relacionadas:

```c
int  check_flags(char *arg);
int  check_split(char *argv, t_stack *stack);
int  parse_arguments(int argc, char **argv, int i, t_stack *stack);
int  is_number(const char *str);
int  check_long(long value);
long ft_atol(const char *nptr);
```

Resumen de uso:

- `check_flags(...)` detecta opciones como `--simple`, `--medium`, `--complex`, `--adaptive` y `--bench`.
- `check_split(...)` separa una cadena con espacios y procesa cada número.
- `is_number(...)` comprueba que el token tenga formato numérico válido.
- `ft_atol(...)` convierte el texto a número.
- `check_long(...)` verifica que el valor quepa en `int`.
- `parse_arguments(...)` coordina todo el recorrido.

## 3. Cómo se rellena la pila

En la versión actual del flujo que sí preserva el orden, la carga se hace con inserción al final:

```c
stack_add_back(stack, node);
```

Eso significa que el orden visual de la pila refleja el orden de llegada del input.

### Ejemplo de carga

Si el input es:

```bash
./push_swap 3 8 1 5
```

Y se mete con `stack_add_back(...)`, la pila queda así:

- `top -> 3`
- después `8`
- después `1`
- `bot -> 5`

O sea, el primer argumento queda arriba y el último queda abajo.

### Nota sobre la posible inversión

Si alguien rellena la pila con inserción al principio:

```c
stack_add_front(stack, node);
```

entonces el orden del input queda invertido.

Ejemplo con el mismo input `3 8 1 5`:

- si insertas al frente, acabas con `top -> 5`
- si insertas al final, acabas con `top -> 3`

Por eso conviene acordar una sola regla entre los dos:

- **orden lógico del input**: el orden en que llega por argumentos
- **orden físico de la pila**: el orden en que quedan los nodos enlazados

En este repositorio, la referencia más clara es la carga con `stack_add_back(...)`, que mantiene el input tal cual.

## 4. Qué significa que la pila esté rellena

La pila se considera rellenada cuando cada valor ya tiene su nodo, está enlazado y el contador `size` coincide con el número de elementos.

Las funciones de utilidad que participan en esto son:

```c
t_node  *node_new(int value, int index);
void    stack_add_front(t_stack *stack, t_node *node);
void    stack_add_back(t_stack *stack, t_node *node);
```

- `node_new(...)` crea el nodo.
- `stack_add_back(...)` o `stack_add_front(...)` lo insertan en la estructura.

## 5. Qué significa estar ordenada

Aquí hay dos formas de verlo, y conviene no mezclarlas:

### Orden por valores

La pila está ordenada por valores cuando los números van de menor a mayor desde `top` hasta `bot`.

Ejemplo:

- `top -> 1 -> 3 -> 5 -> 8 -> bot`

### Orden por índices

Antes de aplicar algoritmos, el proyecto calcula `index` para cada nodo.

```c
static int assign_indices(t_stack *stack);
```

La idea es:

- el valor más pequeño recibe `index = 0`
- el siguiente recibe `index = 1`
- y así sucesivamente

Por tanto, la pila se considera ordenada cuando los `index` suben de arriba a abajo:

- `0, 1, 2, 3, ...`

Eso hace que el criterio sea independiente de cómo se cargó el input.

### Regla práctica

Si quieres saber si la pila ya está bien, no mires solo el valor original del argumento. Mira si el recorrido desde `top` a `bot` sigue el orden ascendente de `index`.

## 6. Operaciones de movimiento

Estas son las operaciones básicas sobre la pila:

```c
void push(t_stack *src, t_stack *dst);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
```

### Qué hace cada una

- `push(src, dst)`: saca el nodo de arriba de `src` y lo mete arriba de `dst`.
- `swap(stack)`: intercambia los dos primeros nodos.
- `rotate(stack)`: el primero pasa al final.
- `reverse_rotate(stack)`: el último pasa al principio.

## 7. Operaciones visibles en salida

Estas funciones son las que imprimen el nombre de la operación:

```c
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
```

Lectura rápida:

- `pa` / `pb`: mover entre pilas
- `sa` / `sb` / `ss`: intercambiar arriba
- `ra` / `rb` / `rr`: rotar hacia abajo el primero
- `rra` / `rrb` / `rrr`: rotar hacia arriba el último

## 8. Cómo se relaciona todo

Resumen mental para compartir con tu compañero:

1. El parsing lee argumentos y valida que sean números.
2. Cada número se convierte en nodo.
3. Los nodos se insertan en la pila, idealmente con `stack_add_back(...)` para no invertir el orden del input.
4. Después se calculan `index` para convertir los valores en una referencia común de orden.
5. La pila se considera ordenada cuando los índices van en orden creciente desde `top`.
6. Las operaciones de movimiento sirven para reorganizar esos nodos hasta llegar a ese estado.

## 9. Idea clave para evitar malentendidos

Si uno de los dos piensa la pila como “orden de entrada” y el otro como “orden de índice”, parece que están describiendo cosas distintas.

La regla que os alinea es esta:

- el input tiene un orden de llegada
- la pila tiene un orden físico de nodos
- el algoritmo decide si está ordenada mirando `index`

Si mantenéis esa convención, no importa si los valores originales llegan en un orden u otro: ambos vais a hablar del mismo estado real de la pila.
