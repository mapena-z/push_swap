*This project was created as part of the 42 curriculum by mapena-z, carlinaq.*

---

# push_swap

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 School" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C" />
</p>

---

## Description

**push_swap** is a 42 project whose goal is to sort a list of integers using only two stacks (`a` and `b`) and a limited set of operations, while minimizing the total number of moves. The project tests understanding of algorithmic complexity: it's not enough to sort, you have to sort *fast* and with the right strategy depending on the input's state.

The program implements four sorting strategies selectable at runtime, plus a benchmark mode that displays detailed performance metrics.

---

## Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile the checker (bonus)
make bonus

# Clean object files
make clean

# Clean everything (objects + binaries)
make fclean

# Recompile from scratch
make re
```

### Usage

```bash
# Basic usage (adaptive algorithm by default)
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

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` / `ss` | Swap the two top elements of a / b / both |
| `pa` / `pb` | Push the top of b→a / a→b |
| `ra` / `rb` / `rr` | Rotate a / b / both |
| `rra` / `rrb` / `rrr` | Reverse rotate a / b / both |

### Error handling

```bash
./push_swap 0 one 2 3   # Error: non-integer argument
./push_swap 3 2 3       # Error: duplicates
./push_swap             # No output (no arguments)
```

---

## Implemented algorithms

### 1. Simple — O(n²): Turk Sort (`--simple`)

An adaptation of insertion sort for two stacks. For each element in `a`, it computes the minimum cost to move it to its correct position in `b` by combining rotations of both stacks simultaneously (`rr` / `rrr`). Once all elements are in `b` in descending order, they are pushed back to `a` with `pa`.

**Justification:** It's the most intuitive algorithm and sufficient for small inputs (≤ 5 elements). For large n its quadratic cost makes it inefficient, but it serves as a baseline and for the `--simple` mode.

### 2. Medium — O(n√n): Chunk Sort (`--medium`)

Divides the index range into `√n` chunks of similar size. On each pass, it moves to `b` every element whose index falls within the current chunk, optimizing rotations to minimize movements. Once everything is in `b`, it's pushed back to `a` in order.

**Justification:** By reducing the problem into blocks of size √n, the number of rotations needed drops considerably compared to O(n²), making it ideal for medium-sized inputs (100–500 elements).

### 3. Complex — O(n log n): Radix Sort (`--complex`)

An LSD (Least Significant Digit) radix sort implementation adapted to stacks. It sorts bit by bit: on each pass, elements with the current bit set to 0 are sent to `b` (`pb`), and those with the bit set to 1 are rotated within `a` (`ra`). After each pass everything is pushed back to `a`. As many passes are needed as bits in the largest index.

**Justification:** Since it operates on normalized indices (0..n-1), the number of bits required is log₂(n), resulting in exactly n·log₂(n) operations in all cases. It's the most predictable and efficient option for large inputs.

### 4. Adaptive (`--adaptive`, default behavior)

Selects the algorithm based on the **disorder index** computed before any move:

| Disorder | Algorithm chosen | Complexity |
|----------|-------------------|------------|
| < 0.2 | Turk Sort (insertion) | O(n) effective |
| 0.2 – 0.5 | Chunk Sort | O(n√n) |
| ≥ 0.5 | Radix Sort | O(n log n) |

The disorder index is the fraction of pairs (i, j) with i < j where `a[i] > a[j]`. It's 0 when sorted and 1 when fully inverted.

**Threshold justification:** With disorder < 0.2 the stack is nearly sorted, so a few swaps and insertions cover the case in linear time. Between 0.2 and 0.5 there's enough disorder for the chunks to amortize the cost well. Above 0.5 the stack is mixed enough that radix, with its uniform cost, becomes the most stable option.

## Resources

### Technical references

- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching* — classic reference on sorting algorithms.
- [Visualgo — Sorting Algorithms](https://visualgo.net/en/sorting) — interactive visualization of sorting algorithms.
- [Wikipedia — Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) — description of the LSD/MSD algorithm.
- [Wikipedia — Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort) — basis of the implemented simple algorithm.
- [42 Docs — Push Swap](https://harm-smits.github.io/42docs/projects/push_swap) — community reference for the project.

### AI usage

AI (Claude) was used as support for the following tasks:

- **Makefile debugging**: diagnosing the relink issue caused by targets in `.PHONY` and timestamp behavior on WSL/NTFS.


In all cases the code was reviewed, understood, and adapted by the authors before being integrated into the project.