# _printf

## Index
- [Description](#description)
- [Features](#features)
- [File Structure](#file-structure)
- [Example Usage](#example-usage)
- [Compilation](#compilation)
- [Requirements](#requirements)
- [Authors](#authors)

## Description
This custom implementation mimics the behavior of the standard C library `printf` for the supported specifiers.
It handles a subset of the original specifiers and demonstrates knowledge of:
- Variadic functions
- Function pointers
- Structs and specifier mapping
- Recursion
- Manual number printing using `write()`
- String formatting logic

## Features
Our `_printf` supports the following conversion specifiers:

| Specifier  | Description                              |
|------------|------------------------------------------|
| `%c`       | Prints a single character                |
| `%s`       | Prints a string                          |
| `%%`       | Prints a percent sign                    |
| `%d`, `%i` | Prints a signed integer                  |
| `%b`       | Prints an unsigned int in binary         |
| `%u`       | Prints an unsigned integer               |
| `%o`       | Prints a number in octal                 |
| `%x`       | Prints a number in lowercase hexadecimal |
| `%X`       | Prints a number in uppercase hexadecimal |

## File Structure
```
_printf/
│
├── _printf.c              # Main printf function
├── functions.c            # Selects correct handler based on specifier
├── functions_2.c          # Extended handlers (numbers, strings, etc.)
├── handl_func.c           # Handler execution + specifier mapping
├── man_3_printf           # Manual page source file for the _printf function
├── main.h                 # Header file with structs & prototypes
└── README.md              # Project documentation
```

## Example Usage
```c
/* Test code */
_printf("Character: %c\n", 'A');
_printf("Hello %s!\n", "World");
_printf("Percent: %%\n");
_printf("Number: %d\n", 1234);
_printf("Number: %i\n", 4321);
_printf("Binary: %b\n", 98);
_printf("Unsigned: %u\n", 3000000000U);
_printf("Octal: %o\n", 255);
_printf("Hex (lowercase): %x\n", 255);
_printf("Hex (UPPERCASE): %X\n", 255);

/* Output */

Character: A
Hello World!
Percent: %
Number: 1234
Number: 4321
Binary: 1100010
Unsigned: 3000000000
Octal: 377
Hex (lowercase): ff
Hex (UPPERCASE): FF

/* Large values (e.g., 3000000000U) are supported as long as your system uses 32-bit or larger unsigned int */
```

## Compilation

To compile all source files into an executable called `printf`, run:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o printf
```

You can then test the program with:

```bash
./printf
```

## Requirements
- Allowed functions:
write, malloc, free, va_start, va_arg, va_end
- No global variables
- Follow Betty coding style
- Compile with:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c
```

## Authors
- Mohammed Saeed Aldosari
- Badriah Barakat Almalki

**This project completed as part of Holberton School Cohort — Riyadh, KSA.**
