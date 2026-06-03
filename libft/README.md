*This project has been created as part of the 42 curriculum by mapena-z.*

# 📚 Libft - Your First C Library

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 School" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C" />
</p>

---

## 📝 Description

The **Libft** project consists of coding our own C library from scratch, recreating key functions from the standard C library (`libc`), as well as additional utilities for string manipulation, memory management, and linked lists.

### 🎯 Objective
The primary purpose of this project is to understand how memory management (`malloc`, `free`), pointers, and data structures work at a low level in C. Without access to native functions, we are forced to manually handle buffer overflows, memory leaks, and undefined behaviors. This library serves as the code foundation that we will use throughout the rest of our 42 cursus projects (such as *get_next_line*, *ft_printf*, *minishell*, etc.).

---

## 📦 Detailed Description of the Library

The library is divided into three main logical blocks. Every single function has been meticulously recreated to mirror the actual behavior of system functions.

### 1. Libc Functions
These functions replicate the behavior of standard tools provided by the operating system:

* **Character Management (`<ctype.h>`)**
    * `ft_isalpha` / `ft_isdigit` / `ft_isalnum` / `ft_isascii` / `ft_isprint`: Type validations for input characters.
    * `ft_toupper` / `ft_tolower`: Converting letters between uppercase and lowercase using the correct casting to `char`.
* **Basic Memory Management (`<string.h>` / `<stdlib.h>`)**
    * `ft_memset`: Fills a memory block with a specific byte.
    * `ft_bzero`: Sets a memory block to zero (`'\0'`).
    * `ft_memcpy` / `ft_memmove`: Copies memory regions safely from a source to a destination (handling memory overlap correctly).
    * `ft_memchr` / `ft_memcmp`: Searches and compares raw bytes inside memory blocks.
    * `ft_calloc`: Dynamic allocation of memory initialized to zero to prevent garbage values.
* **String Manipulation (`<string.h>`)**
    * `ft_strlen`: Computes the exact length of a string.
    * `ft_strlcpy` / `ft_strlcat`: String copy and concatenation that guarantees null-termination and prevents buffer overflows.
    * `ft_strchr` / `ft_strrchr`: Locates the first or last occurrence of a character within a string (protected against bit overflows).
    * `ft_strncmp`: Compares two strings up to a given number `n` of characters.
    * `ft_strnstr`: Locates a substring inside a main string within a character limit.
    * `ft_strdup`: Duplicates a string by allocating new memory on the *heap*.
    * `ft_atoi`: Converts a character string representing a number into a signed integer (`int`), handling spaces and signs.

### 2. Additional Functions (42 Specific Custom Utilities)
Advanced tools that do not exist in the standard library but are crucial for daily software development:

* `ft_substr`: Extracts a substring from a string starting at a specified index with a specific length.
* `ft_strjoin`: Concatenates two strings into a newly allocated region of dynamic memory.
* `ft_strtrim`: Trims specific character sets from both the beginning and the end of a string.
* `ft_split`: Splits a string into a two-dimensional array (`char **`) using a delimiter character. It includes robust memory cleanup if an intermediate `malloc` fails.
* `ft_itoa`: Converts a numerical integer into a text string.
* `ft_strmapi` / `ft_striteri`: Applies external functions to each character of a string using function pointers.
* `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd`: Writes characters, strings, or numbers into a specified file descriptor (such as `1` for standard output or `2` for errors).

### 3. Linked List Functions
Tools for managing the dynamic data structure `t_list`:
* `ft_lstnew`: Initializes a new node.
* `ft_lstadd_front` / `ft_lstadd_back`: Inserts nodes at either the beginning or the end of the list.
* `ft_lstsize`: Counts the elements in the list.
* `ft_lstlast`: Returns the last node of the list.
* `ft_lstdelone` / `ft_lstclear`: Frees individual nodes or the entire list using custom deletion function pointers.
* `ft_lstiter` / `ft_lstmap`: Iterates over the list, applying modifications to the contents of each node.

---

## 🛠️ Instructions

### Prerequisites
You will need a UNIX-based compiler like `gcc` or `clang` along with the `make` build tool utility.

### Compilation Rules
Open your terminal at the root of the project and use the following compilation rules provided by the custom Makefile:

* **`make`** / **`make all`**: Compiles all mandatory source files into binary object files (`.o`) and packages them together into the final static library archive file (`libft.a`).
* **`make clean`**: Removes all intermediate object files (`.o`) generated during compilation, keeping your workspace tidy.
* **`make fclean`**: Performs a full cleanup. It removes all intermediate object files (`.o`) and also deletes the compiled static library file (`libft.a`).
* **`make re`**: Force-rebuilds the entire library from scratch. It executes `fclean` followed immediately by `make` (or `make all`).

## 📚 Resources

### Classic References

* Linux Man Pages: Official documentation outlining the expected behaviors of standard libc functions.

* GeeksforGeeks - C Programming Language: Excellent deep dives into pointers, strings, and dynamic memory allocation.

* GNU C Library Documentation: Deep technical references regarding core library design.