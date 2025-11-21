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
	int i = 0, len = 0, ibuf = 0, ret;
	char buffer[1024];
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			handl_buf(buffer, format[i], &ibuf);
			len++;
		}
		else
		{
			ret = handle_print(format, &i, &args, buffer, &ibuf);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		i++;
	}
	write(1, buffer, ibuf);

	va_end(args);
	return (len);
}