#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "push_swap.h"

/* Initialize benchmark context */
t_benchmark	*bench_new(void);
void		bench_free(t_benchmark *bench);
/* Print benchmark results */
void	bench_print(t_benchmark *bench);
void	setup_benchmark(t_stack *stack_a, t_benchmark *bench, int argc, char **argv);

int	is_bench_mode(int argc, char **argv);

#endif