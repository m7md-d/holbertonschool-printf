#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int print_char(va_list *args);
int print_str(va_list *args);
int print_per(va_list *args);
int print_int(va_list *args);

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

#endif /* MAIN_H */
