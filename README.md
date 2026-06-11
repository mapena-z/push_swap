# push_swap

Repositorio orientado a ordenar una pila usando dos estructuras principales, `a` y `b`, y un conjunto de operaciones basicas sobre nodos enlazados.

La idea de este documento no es explicar toda la logica del algoritmo, sino dejar claro como estan montadas las estructuras, como se cargan los datos y que hace cada funcion publica.

## Vision general

En este proyecto hay dos niveles de representacion:

- `t_node`: representa un valor individual dentro de la pila.
- `t_stack`: representa la pila completa, con punteros al inicio y al final.

Ademas, existe `t_push_swap`, que agrupa las dos pilas y metadatos de ejecucion para estrategias mas completas.

### Comparacion rapida con la referencia

La referencia que has pasado usa una sola estructura de nodo con mas campos de control:

- `prev`, `next`, `target_node`
- `push_cost`
- `above_median`
- `cheapest`

En este repositorio la estructura es mas simple:

- el nodo solo guarda `value`, `index` y `next`
- la pila guarda `top`, `bot`, `size` y `name`
- los datos de estrategia se separan en `t_push_swap`

Eso hace que la base sea mas limpia y facil de leer, aunque parte del trabajo de coste y decision se mueve fuera del nodo.

## Estructuras

### `t_node`

```c
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}   t_node;
```

- `value`: numero original leido por argumentos.
- `index`: posicion relativa tras ordenar los valores de menor a mayor.
- `next`: siguiente nodo de la pila.

Uso principal: almacenar cada numero ya validado.

### `t_stack`

```c
typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	char	name;
}   t_stack;
```

- `top`: primer elemento de la pila.
- `bot`: ultimo elemento de la pila.
- `size`: numero de nodos que contiene.
- `name`: identificador de la pila, normalmente `a` o `b`.

Uso principal: trabajar con una lista enlazada simple sin perder acceso rapido al inicio y al final.

### `t_push_swap`

```c
typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	int		total_ops;
	double	disorder;
	char	*strat_name;
	char	*strat_complex;
	int		n_sa;
	int		n_sb;
	int		n_ss;
	int		n_pa;
	int		n_pb;
	int		n_ra;
	int		n_rb;
	int		n_rr;
	int		n_rra;
	int		n_rrb;
	int		n_rrr;
}   t_push_swap;
```

- agrupa ambas pilas
- guarda contadores de operaciones
- permite llevar estadisticas de una estrategia mas avanzada

## Como se llena la estructura

El flujo normal de carga es este:

1. Se validan los argumentos de entrada.
2. Se comprueba que cada token sea un numero valido.
3. Se convierte el texto a entero largo.
4. Se crea un nodo con el valor.
5. Se inserta ese nodo en la pila.

En terminos de funciones, el camino habitual es:

```c
int     parse_arguments(int argc, char **argv, int i, t_stack *stack);
int     check_split(char *argv, t_stack *stack);
int     is_number(const char *str);
int     check_long(long value);
long    ft_atol(const char *nptr);
void    push(t_stack *stack, int value);
void    stack_add_back(t_stack *stack, t_node *node);
```

### Que hace cada paso

- `parse_arguments(...)` recorre los argumentos y lanza el proceso de validacion/carga.
- `check_split(...)` separa una cadena con espacios y procesa cada numero por separado.
- `is_number(...)` valida el formato numerico.
- `check_long(...)` evita desbordamientos de `int`.
- `ft_atol(...)` convierte el texto a `long`.
- `push(...)` en la capa de parsing actua como helper para ir metiendo valores en la estructura.
- `stack_add_back(...)` enlaza el nodo al final de la pila.

### Nota importante sobre nombres

En el proyecto aparece el nombre `push` en dos contextos:

- como helper de carga de datos
- como operacion de movimiento entre pilas

Conceptualmente son cosas distintas. Si alguien revisa el codigo, conviene leerlo asi para no confundir la carga inicial con la operacion `pa/pb`.

## Operaciones de movimiento

Estas funciones son las que modifican la posicion de los nodos en las pilas.

### Operaciones base

```c
void push(t_stack *src, t_stack *dst);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
```

- `push(src, dst)`: mueve el nodo superior de `src` al inicio de `dst`.
- `swap(stack)`: intercambia los dos primeros nodos.
- `rotate(stack)`: sube el primer nodo al final.
- `reverse_rotate(stack)`: baja el ultimo nodo al principio.

### Operaciones impresas

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

- `pa` y `pb`: hacen un `push` entre pilas y escriben la operacion.
- `sa`, `sb`, `ss`: aplican `swap`.
- `ra`, `rb`, `rr`: aplican `rotate`.
- `rra`, `rrb`, `rrr`: aplican `reverse_rotate`.

### Salida de movimientos

```c
void print_mov(t_stack *stack, char mov);
```

- recibe la pila y una letra base del movimiento
- imprime el codigo de operacion con el nombre de la pila

Ejemplo conceptual:

- `sa`
- `pb`
- `rr`

## Utilidades de pila

### Creacion y destruccion

```c
t_node  *node_new(int value, int index);
void    node_free(t_node *node);
t_stack *stack_new(char name);
void    stack_clear(t_stack *stack);
void    stack_free(t_stack *stack);
```

- `node_new(value, index)`: crea un nodo nuevo.
- `node_free(node)`: libera un nodo.
- `stack_new(name)`: crea una pila vacia con nombre.
- `stack_clear(stack)`: libera todos los nodos pero mantiene la pila.
- `stack_free(stack)`: libera nodos y estructura de pila.

### Insercion y busqueda

```c
void    stack_add_front(t_stack *stack, t_node *node);
void    stack_add_back(t_stack *stack, t_node *node);
t_node  *stack_get_at(t_stack *stack, int index);
int     stack_min_pos(t_stack *stack);
int     stack_max_pos(t_stack *stack);
int     stack_find_index(t_stack *stack, int index);
```

- `stack_add_front(...)`: mete un nodo al principio.
- `stack_add_back(...)`: mete un nodo al final.
- `stack_get_at(...)`: recupera el nodo en una posicion concreta.
- `stack_min_pos(...)`: devuelve la posicion del indice mas pequeno.
- `stack_max_pos(...)`: devuelve la posicion del indice mas grande.
- `stack_find_index(...)`: busca la posicion de un indice concreto.

## Validacion de entrada

```c
int is_number(const char *str);
int check_long(long value);
long ft_atol(const char *nptr);
int check_flags(char *arg);
int check_split(char *argv, t_stack *stack);
int parse_arguments(int argc, char **argv, int i, t_stack *stack);
```

- `is_number(...)`: comprueba si una cadena tiene formato numerico valido.
- `check_long(...)`: valida que el numero entre en rango de `int`.
- `ft_atol(...)`: convierte una cadena a `long`.
- `check_flags(...)`: detecta flags de ejecucion.
- `check_split(...)`: divide una cadena con espacios y procesa cada token.
- `parse_arguments(...)`: coordina toda la lectura de argumentos.

## Limpieza

```c
void free_stacks(t_stack *stack);
void free_words(char **words);
```

- `free_stacks(...)`: libera una lista de pilas.
- `free_words(...)`: libera un array de strings devuelto por `ft_split`.

## Algoritmos

```c
void alg_two(t_stack *stack);
void alg_three(t_stack *a);
void alg_four(t_stack *a, t_stack *b);
void alg_five(t_stack *a, t_stack *b);
void insertion_basic(t_stack *stack_a, t_stack *stack_b);
void insertion_sort(t_stack *stack_a, t_stack *stack_b);
```

Todas estas funciones reciben punteros a pila y no devuelven nada.

La idea general es:

- `alg_two`, `alg_three`, `alg_four`, `alg_five`: soluciones cortas para pocos elementos.
- `insertion_basic` e `insertion_sort`: estrategias de ordenacion mas generales.

## Debug

```c
void stack_print(t_stack *stack);
void stack_print_both(t_stack *a, t_stack *b);
```

- imprimen el contenido y el tamano de cada pila
- sirven para comprobar estados intermedios durante pruebas


