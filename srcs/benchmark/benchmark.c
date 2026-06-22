#include "../../includes/algorithms.h"
#include "../../includes/push_swap.h"
#include "../../includes/benchmark.h"
#include "../../libft/libft.h"

static void	bench_putdisorder_fd(double disorder, int fd)
{
	int	disorder_100;

	disorder_100 = (int)(disorder * 100 + 0.5);
	if (disorder_100 >= 100)
	{
		ft_putstr_fd("1.00", fd);
		return ;
	}
	ft_putstr_fd("0.", fd);
	if (disorder_100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(disorder_100, fd);
}

static void	bench_putlabelnbr_fd(const char *label, int number, int fd)
{
	ft_putstr_fd((char *)label, fd);
	ft_putnbr_fd(number, fd);
}

t_benchmark	*bench_new(void)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	ft_bzero(bench, sizeof(t_benchmark));
	bench->strategy_name = NULL;
	bench->adaptive_strategy = NULL;
	bench->strategy_complexity = NULL;
	return (bench);
}

void	bench_free(t_benchmark *bench)
{
	if (!bench)
		return ;
	free(bench);
}

void	bench_print(t_benchmark *bench) // tiene que salir por el 2
{
	if (!bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	bench_putdisorder_fd(bench->disorder, 2);
	ft_putchar_fd('\n', 2);
	if (bench->adaptive_strategy)
	{
		ft_putstr_fd("[bench] strategy: adaptive / ", 2);
		ft_putstr_fd((char *)bench->adaptive_strategy, 2);
		ft_putstr_fd(" (", 2);
		ft_putstr_fd(bench->strategy_complexity, 2);
		ft_putstr_fd(")\n", 2);
	}
	else
	{
		ft_putstr_fd("[bench] strategy: ", 2);
		ft_putstr_fd(bench->strategy_name, 2);
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(bench->strategy_complexity, 2);
		ft_putchar_fd('\n', 2);
	}
	bench_putlabelnbr_fd("[bench] total ops: ", bench->ops.total_ops, 2);
	ft_putchar_fd('\n', 2);
	bench_putlabelnbr_fd("[bench]  sa: ", bench->ops.n_sa, 2);
	bench_putlabelnbr_fd("    sb: ", bench->ops.n_sb, 2);
	bench_putlabelnbr_fd("    ss: ", bench->ops.n_ss, 2);
	bench_putlabelnbr_fd("  pa: ", bench->ops.n_pa, 2);
	bench_putlabelnbr_fd("    pb: ", bench->ops.n_pb, 2);
	ft_putchar_fd('\n', 2);
	bench_putlabelnbr_fd("[bench]  ra: ", bench->ops.n_ra, 2);
	bench_putlabelnbr_fd("    rb: ", bench->ops.n_rb, 2);
	bench_putlabelnbr_fd("    rr: ", bench->ops.n_rr, 2);
	bench_putlabelnbr_fd("  rra: ", bench->ops.n_rra, 2);
	bench_putlabelnbr_fd("   rrb: ", bench->ops.n_rrb, 2);
	bench_putlabelnbr_fd("   rrr: ", bench->ops.n_rrr, 2);
	ft_putchar_fd('\n', 2);
}