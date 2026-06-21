#ifndef STACK_H
# define STACK_H

#include "push_swap.h"

/* Node creation and destruction */
t_node	*node_new(int value, int index);
void	node_free(t_node *node);

/* Stack creation and destruction */
t_stack	*stack_new(char name);
void	stack_clear(t_stack *stack);
void	stack_free(t_stack *stack_a, t_stack *stack_b);
void set_fd(t_stack *stack_a, t_stack *stack_b, int fd, t_benchmark *bench);

/* Stack operations */
void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);

/* Stack search and info */
t_node	*stack_get_at(t_stack *stack, int index);
int		stack_min_pos(t_stack *stack);
int		stack_max_pos(t_stack *stack);
int		stack_find_index(t_stack *stack, int index);
t_node	*stack_find_pos(t_stack *stack, int n);

#endif