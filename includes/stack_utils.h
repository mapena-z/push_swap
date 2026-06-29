/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:26:25 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:27:26 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "push_swap.h"

/* Node creation and destruction */
t_node	*node_new(int value, int index);

/* Stack creation and destruction */
t_stack	*stack_new(char name);
void	stack_clear(t_stack *stack);
void	stack_free(t_stack *stack_a, t_stack *stack_b);
void	set_fd(t_stack *stack_a, t_stack *stack_b);

/* Stack operations */
void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);

/* Stack search and info */
t_node	*stack_get_at(t_stack *stack, int index);
int		stack_min_pos(t_stack *stack);
int		stack_max_pos(t_stack *stack);
int		stack_find_index(t_stack *stack, int index);

#endif