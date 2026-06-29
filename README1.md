This project was created as part of the 42 curriculum by mapena-z and carlinaq.

# push_swap
<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 School" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C" />
</p>

---
## Description

**push_swap** is a 42 project whose goal is to sort a list of integers using only two stacks (`a` and `b`) and a limited set of operations while minimizing the total number of moves. The project tests your understanding of algorithmic complexity: it is not enough to sort the data—you must sort it efficiently using the appropriate strategy depending on the input state.

The program implements four selectable sorting strategies that can be chosen at runtime, as well as a benchmark mode that displays detailed performance metrics.

## Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile the checker (bonus)
make checker

# Remove object files
make clean

# Remove everything (objects + binaries)
make fclean

# Recompile from scratch
make re
```

## Usage

```bash
# Basic usage (default adaptive algorithm)
./push_swap 4 67 3 87 23

# Force a specific algorithm
./push_swap --simple  3 2 1 4 5
./push_swap --medium  3 2 1 4 5
./push_swap --complex 3 2 1 4 5
./push_swap --adaptive 3 2 1 4 5

# Benchmark mode (prints metrics to stderr)
./push_swap --bench 3 2 1 4 5

# Combine flags
./push_swap --bench --complex 3 2 1 4 5

# Verify with the checker
./push_swap 3 2 1 | ./checker 3 2 1

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Test with 500 random numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

## Available Operations

| Operation       | Description                                     |
| --------------- | ----------------------------------------------- |
| sa / sb / ss    | Swap the first two elements of `a` / `b` / both |
| pa / pb         | Push the top element from `b → a` / `a → b`     |
| ra / rb / rr    | Rotate `a` / `b` / both                         |
| rra / rrb / rrr | Reverse rotate `a` / `b` / both                 |

## Error Handling

```bash
./push_swap 0 one 2 3   # Error: non-integer argument
./push_swap 3 2 3       # Error: duplicate values
./push_swap             # No output (no arguments)
```

# Contributions

| Module           | Files                                                                   | Author   |
| ---------------- | ----------------------------------------------------------------------- | -------- |
| Complete parsing | `parsing.c`, `parsing_utils.c`, `validation.c`, `push_carl_propuesta.c` | mapena-z |
| Checker (bonus)  | `main_checker.c`, `checker_utils.c`                                     | mapena-z |
| Benchmark        | `benchmark.c`, `benchmark_print.c`, `bench_utils.c`                     | mapena-z |
| Main             | `main.c`                                                                | mapena-z |

# Resources

## Technical References

* **Knuth, D. E.** — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — classic reference on sorting algorithms.
* **VisuAlgo** — *Sorting Algorithms* — interactive visualization of sorting algorithms.
* **Wikipedia** — *Radix Sort* — description of the LSD/MSD radix sort algorithm.
* **Wikipedia** — *Insertion Sort* — basis of the implemented simple algorithm.
* **42 Docs** — *Push Swap* — community reference for the project.

# AI Usage

AI (Claude) was used as assistance for the following tasks:

* **Makefile debugging:** diagnosing the relink issue involving `.PHONY` targets and timestamp behavior on WSL/NTFS.

In all cases, the generated code and suggestions were reviewed, fully understood, and adapted by the authors before being integrated into the project.
