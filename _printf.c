#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Produces output according to a format string.
 * @format: The character string that specifies the format of the output.
 *
 * Description: This function prints a formatted string to the standard output.
 * It handles format specifiers like %c, %s, %%, %d, and %i.
 * Return: The total number of characters printed to the output.
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0, last_print = 0;
	va_list args;
	prt_f prt_fun[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_per},
		{'i', print_int},
		{'d', print_int},
		{'\0', NULL}
	};
	va_start(args, format);

	while (format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%' && format[i + 1])
		{
			len += write(1, &format[last_print], i - last_print);
			i++;
			while (prt_fun[j].c != '\0')
			{
				if (format[i] == prt_fun[j].c)
				{
					len += prt_fun[j].func_ptr(&args);
					last_print = i + 1;
					break;
				}
				j++;
			}
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			last_print = i;
			break;
		}
		i++;
	}
	if (i - 1 != last_print)
		len += (write(1, &format[last_print], i - last_print));
	va_end(args);
	return (len);
}
