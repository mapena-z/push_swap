/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:21:08 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/28 14:47:16 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

int		check_flags(char *arg);
int		check_split(char *argv, t_stack *stack);
int		parse_arguments(int argc, char **argv, int i, t_stack *stack);
int		is_number(const char *str);
int		check_long(long value);
long	ft_atol(const char *nptr);
void	free_words(char **words);
void	ft_push(t_stack *stack, int value);
int		is_duplicate(t_stack *stack);
void	stack_index(t_stack *stack);
int		has_flag(int argc, char **argv, char *flag);
int		first_value_arg(int argc, char **argv);
int		init_and_parse(t_stack **s_a, t_stack **s_b, int argc, char **argv);
int		is_algo_flag(char *arg);
int		is_extra_flag(char *arg);
int		validate_flags(int argc, char **argv);

#endif
