#include "../../includes/algorithms.h"
#include "../../includes/push_swap.h"
#include "../../includes/benchmark.h"

int	is_bench_mode(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}



