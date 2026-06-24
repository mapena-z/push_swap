/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:42:03 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 18:26:18 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_metrics
{
	int	total_ops;
	int	n_sa;
	int	n_sb;
	int	n_ss;
	int	n_pa;
	int	n_pb;
	int	n_ra;
	int	n_rb;
	int	n_rr;
	int	n_rra;
	int	n_rrb;
	int	n_rrr;
}	t_metrics;

typedef struct s_benchmark
{
	double		disorder;
	char		*strategy_name;
	const char	*adaptive_strategy;
	char		*strategy_complexity;
	t_metrics	ops;
}	t_benchmark;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bot;
	int			size;
	char		name;
	char		fd;
	t_benchmark	*bench;
}	t_stack;

#endif