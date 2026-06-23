/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:55:17 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/23 11:56:46 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/algorithms.h"
#include "../../includes/push_swap.h"
#include "../../includes/benchmark.h"
#include "../../libft/libft.h"

void	print_ops_group1(t_benchmark *bench)
{
	bench_putlabelnbr_fd("[bench]   sa: ", bench->ops.n_sa, 2);
	bench_putlabelnbr_fd("    sb: ", bench->ops.n_sb, 2);
	bench_putlabelnbr_fd("    ss: ", bench->ops.n_ss, 2);
	bench_putlabelnbr_fd("   pa: ", bench->ops.n_pa, 2);
	bench_putlabelnbr_fd("    pb: ", bench->ops.n_pb, 2);
	ft_putchar_fd('\n', 2);
}

void	print_ops_group2(t_benchmark *bench)
{
	bench_putlabelnbr_fd("[bench]   ra: ", bench->ops.n_ra, 2);
	bench_putlabelnbr_fd("    rb: ", bench->ops.n_rb, 2);
	bench_putlabelnbr_fd("    rr: ", bench->ops.n_rr, 2);
	bench_putlabelnbr_fd("  rra: ", bench->ops.n_rra, 2);
	bench_putlabelnbr_fd("   rrb: ", bench->ops.n_rrb, 2);
	bench_putlabelnbr_fd("   rrr: ", bench->ops.n_rrr, 2);
	ft_putchar_fd('\n', 2);
}
