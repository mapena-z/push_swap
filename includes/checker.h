/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:49:53 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/16 23:10:20 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	read_input(t_stack *stack_a, t_stack *stack_b, char *line);
void	final_check(t_stack *stack_a, t_stack *stack_b);
void	checker_error(t_stack *stack_a, t_stack *stack_b, char *line);
int		is_stack_sorted(t_stack *stack);

#endif