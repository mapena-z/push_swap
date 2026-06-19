#include "../../includes/algorithms.h"
#include "../../includes/push_swap.h"
#include "../../includes/benchmark.h"
#include "../../libft/libft.h"

t_benchmark	*bench_new(void)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	ft_bzero(bench, sizeof(t_benchmark));
	bench->strategy_name = NULL;
	bench->strategy_complexity = NULL;
	return (bench);
}

void	bench_free(t_benchmark *bench)
{
	if (!bench)
		return ;
	if (bench->strategy_name)
		free(bench->strategy_name);
	if (bench->strategy_complexity)
		free(bench->strategy_complexity);
	free(bench);
}

void	ft_printf_disorder(double disorder)
{
	int	disorder_100;

	disorder_100 = (int)(disorder * 100 + 0.5);

	if (disorder_100 >= 100)
		ft_printf("1.00");
	else
	{
		ft_printf("0.");
		if (disorder_100 < 10)
			ft_printf("0");
		ft_printf("%d\n", disorder_100);
	}
}

void	bench_print(t_benchmark *bench)
{
	if (!bench)
		return ;
	ft_printf("[bench] disorder: ");
	ft_printf_disorder(bench->disorder);
	ft_printf("[bench] strategy: %s / %s\n", bench->strategy_name, bench->strategy_complexity);
	ft_printf("[bench] total ops: %d\n", bench->ops.total_ops);
	ft_printf("[bench]  sa: %d    sb: %d    ss: %d", bench->ops.n_sa, bench->ops.n_sb, bench->ops.n_ss);
	ft_printf("  pa: %d    pb: %d\n", bench->ops.n_pa, bench->ops.n_pb);
	ft_printf("[bench]  ra: %d    rb: %d    rr: %d", bench->ops.n_ra, bench->ops.n_rb, bench->ops.n_rr);
	ft_printf("  rra: %d   rrb: %d   rrr: %d\n", bench->ops.n_rra, bench->ops.n_rrb, bench->ops.n_rrr);
}