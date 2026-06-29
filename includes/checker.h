/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:49:53 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/23 11:30:11 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "operations.h"
# include "stack_utils.h"

int		init_checker(t_stack **stack_a, t_stack **stack_b,
			int argc, char **argv);
void	read_input(t_stack *stack_a, t_stack *stack_b, char *line);
void	final_check(t_stack *stack_a, t_stack *stack_b);
void	checker_error(t_stack *stack_a, t_stack *stack_b, char *line);
int		is_stack_sorted(t_stack *stack);

#endif