/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:42:03 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/10 12:06:54 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	char	name;
}	t_stack;

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
} t_push_swap;

int		is_number(const char *str);
int		check_long(long value);
long	ft_atol(const char *nptr);
int		check_flags(char *arg);
int		check_split(char *argv);
int		parse_arguments(int argc, char **argv, int i);

#endif