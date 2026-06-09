#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "push_swap.h"

void print_mov(t_stack *stack, char mov);
/* Stack operations */
void	push(t_stack *stack_out, t_stack *stack_in);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/* Operations with output */
void	pa(t_stack *out, t_stack *in);
void	pb(t_stack *out, t_stack *in);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif