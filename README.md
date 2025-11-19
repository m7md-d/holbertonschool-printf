# _printf


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

| Specifier | Description |
|----------|-------------------------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%%` | Prints a percent sign |
| `%d, %i` | Prints a decimal number |

## File Structure
```
_printf/
│
├── _printf.c              # Main printf function
├── functions.c            # Selects correct handler based on specifier
├── man_3_printf           # Manual page source file for the _printf function
├── main.h                 # Header file with structs & prototypes
└── README.md              # Project documentation
```

## How `_printf` Works
  
1. `_printf` loops through the format string.
2. When it sees a `%`, it checks the next character.
3. `_printf` check `prt_fun`, which:
- Matches the specifier to a handler function
- Calls that function using a function pointer
4. The handler function:
- Extracts its argument from `va_list`
- Prints it using `write()`
- Returns how many characters were printed
5. `_printf` adds the returned value to its total count
6. `_printf` returns the number of printed characters
 

## Example Usage
### Test Code
```c
_printf("Character: %c\n", 'A');
_printf("Hello %s!\n", "World");
_printf("Percent: %%\n");
_printf("Number: %d\n", 1234);
_printf("Number: %i\n", 4321);


/* Output */

Character: A
Hello World!
Percent: %
Number: 1234
Number: 4321
```

### Compilation

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

## Notes
This project does not handle:
- Field width
- Precision
- Flags (+, space, #, 0, -)
- Length modifiers (l, h)
