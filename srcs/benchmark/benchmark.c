#include "../../includes/algorithms.h"
#include "../../includes/push_swap.h"
#include "../../includes/benchmark.h"
#include "../../libft/libft.h"

void	bench_putdisorder_fd(double disorder, int fd)
{
	int	disorder_100;

	disorder_100 = (int)(disorder * 100 + 0.5);
	if (disorder_100 >= 100)
	{
		ft_putstr_fd("100.00%", fd);
		return;
	}
	ft_putnbr_fd(disorder_100, fd);
	ft_putstr_fd(".00%", fd);
}

void	bench_putlabelnbr_fd(const char *label, int number, int fd)
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

void bench_print(t_benchmark *bench)
{
	if (!bench)
		return;
	ft_putstr_fd("[bench] disorder: ", 2);
	bench_putdisorder_fd(bench->disorder, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (bench->adaptive_strategy)
	{
		ft_putstr_fd("Adaptive / ", 2);
		ft_putstr_fd((char *)bench->adaptive_strategy, 2);
	}
	else
	{
		ft_putstr_fd(bench->strategy_name, 2);
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(bench->strategy_complexity, 2);
	}
	ft_putchar_fd('\n', 2);
	bench_putlabelnbr_fd("[bench] total_ops: ", bench->ops.total_ops, 2);
	ft_putchar_fd('\n', 2);
	print_ops_group1(bench);
	print_ops_group2(bench);
}
