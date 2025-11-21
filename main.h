#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

int print_char(va_list *args);
int print_str(va_list *args);
int print_per(va_list *args);
int print_int(va_list *args);

int print_binary(va_list *args, char buffer[], int *ibuf);

int print_unsigned(va_list *args, char buffer[], int *ibuf);
int print_octal(va_list *args, char buffer[], int *ibuf);
int print_hex(va_list *args, char buffer[], int *ibuf);
int print_HEX(va_list *args, char buffer[], int *ibuf);

/**
 * struct prt_fun - Structure to map format specifiers to handler functions.
 * @c: The character format specifier (e.g., 'c', 's', 'd').
 * @func_ptr: A function pointer that points to the function designed to
 * handle the printing for the corresponding format specifier. The function
 * typically takes a va_list pointer and returns an integer (the count
 * of characters printed).
 *
 * typedef prt_f: A shorter alias for struct prt_fun.
 */
typedef struct prt_fun
{
	char c;
	int (*func_ptr)(va_list *);
} prt_f;

void handl_buf(char buffer[], char c, int *ibuf);
int handle_print(const char *fmt, int *i, va_list *args, char buffer[], int *ibuf);

#endif /* MAIN_H */
