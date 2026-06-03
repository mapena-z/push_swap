*This project has been created as part of the 42 curriculum by mapena-z.*

# ft_printf

<p align="center">
  <img src="https://img.shields.io/badge/School-42_Madrid-black?style=for-the-badge" alt="42 School">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C">
</p>

## 📋 Description

The **ft_printf** project consists of recreating the famous formatted print function `printf` from the C standard library (`<stdio.h>`). The primary objective of this project is to deepen the understanding of how functions with variable arguments (**variadic functions**) work internally and to learn how to parse structured data streams efficiently.

The developed function processes an initial format string and sequentially prints a series of data corresponding to the mandatory format specifiers, returning with mathematical precision the exact number of bytes written to the standard output (`stdout`).

---

## 🛠️ Installation and Usage Instructions

### Prerequisites

A UNIX environment (Linux, macOS) is required, along with a basic compiler (`gcc` or `clang`) and the `make` automation utility.

### Compiling the Library

To compile the project and generate the static library file `libftprintf.a`, clone this repository and run the following command inside the root folder:

```bash
make
```

The Makefile includes the standard rules required by 42 regulations:

- **make all**: Compiles the source files and packages the library along with the external libft silently, using a customized visual interface.
- **make clean**: Deletes the generated object files (`.o`) from both ft_printf and libft.
- **make fclean**: Deletes the object files and purges the final compiled binaries (`libftprintf.a`).
- **make re**: Performs a clean recompilation from scratch by executing `fclean` followed by `all`.

### Incorporating into Your Own Projects

To use this function in any C program, include the header file and call the function:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Printing a number: %d and a hex: %x\n", 42, 42);
	return (0);
}
```

Compile your executable by linking the compiled static library:

```bash
cc main.c libftprintf.a -o my_program
```

---

## 📐 Technical Decisions: Algorithm and Data Structures

### Justification of the Parsing Algorithm

The implemented algorithm is based on a **Single-pass Stream Parsing** approach. The execution thread traverses the string character by character through a simple loop.

When it encounters an ordinary character, it triggers a direct system call (`write`) to output it to the screen immediately.

Upon detecting a `%` escape character, it momentarily suspends the ordinary flow, advances the pointer, and enters a conditional dispatcher function (`set_format`). This algorithmic technique guarantees a computational complexity of **O(n)** in time and **O(1)** in space, radically minimizing memory usage on the stack.

For complex numerical operations (conversion to base 10 and base 16 hexadecimal), a **Recursive Conversion by Successive Divisions** algorithm was chosen. This avoids the need to declare static or dynamic buffers to store the number in reverse, safely delegating storage to the system's call stack in an optimal way that complies with the Norminette.

### Justification of Data Structures

Due to the lightweight nature of the project and the strict restrictions of the Norminette, the primary data structure used is the **Linear Stream of Variable Arguments** provided by native C macros via the opaque `va_list` type.

Complex structures (such as linked lists or trees) were not used because data is read and discarded sequentially in real time, making any additional dynamic memory abstraction inefficient.

For control data, primitive types of fixed integer width (`uintptr_t`, `unsigned long`) are used to ensure that no bit truncation occurs when handling 64-bit pointer addresses on modern computing architectures.

---

## 📚 Resources and Artificial Intelligence Usage

### Consulted References

- UNIX man pages: `man 3 printf`, `man 3 stdarg`
- C99 / ISO C Standard: Documentation regarding the behavior of pointers and adaptive sizing integers (`uintptr_t`)
- Tutorials on Variadic Functions: GNU C Library official guides on the correct usage of `va_start` and `va_end` macros

### AI Usage Declaration

In compliance with academic transparency policies, it is declared that an Artificial Intelligence (AI) Assistant was used in the following sections of this project's development:


#### Makefile Refactoring

Used to de-link the ASCII header from the implicit object compilation rule, fixing the issue of cyclical and repetitive banner printing in the terminal.

