#ifndef BENCHMARK_H
# define BENCHMARK_H

# include "push_swap.h"

t_benchmark	*bench_new(void);
void	bench_print(t_benchmark *bench);
void	setup_benchmark(t_stack *stack_a, int argc, char **argv);
void create_bench(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
int	is_bench_mode(int argc, char **argv);

/*Utils para el benchmark por Norma*/
void	print_ops_group1(t_benchmark *bench);
void	print_ops_group2(t_benchmark *bench);
void	bench_putdisorder_fd(double disorder, int fd);
void	bench_putlabelnbr_fd(const char *label, int number, int fd);

#endif