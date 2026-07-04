/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:26:25 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/30 09:18:37 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "push_swap.h"

t_node	*node_new(int value, int index);

t_stack	*stack_new(char name);
void	stack_clear(t_stack *stack);
void	stack_free(t_stack *stack_a, t_stack *stack_b);
void	set_fd(t_stack *stack_a, t_stack *stack_b);

void	stack_add_front(t_stack *stack, t_node *node);
void	stack_add_back(t_stack *stack, t_node *node);

t_node	*stack_get_at(t_stack *stack, int index);
int		stack_min_pos(t_stack *stack);
int		stack_max_pos(t_stack *stack);
int		stack_find_index(t_stack *stack, int index);
t_node	*stack_find_pos(t_stack *stack, int n);

#endif