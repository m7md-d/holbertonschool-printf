#include "main.h"
#include <unistd.h>

/**
 * handl_buf - Concatenates the buffer characters
 * @buffer: Array of characters
 * @c: Character to append
 * @ibuf: Index of buffer pointer
 * Return: Nothing
 */
void handl_buf(char buffer[], char c, int *ibuf)
{
	if (*ibuf == 1024)
	{
		write(1, buffer, *ibuf);
		*ibuf = 0;
	}
	buffer[*ibuf] = c;
	(*ibuf)++;
}

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string
 * @i: Index pointer
 * @args: List of arguments
 * @buffer: Buffer array
 * @ibuf: Buffer index pointer
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *i, va_list *args, char buffer[], int *ibuf)
{
	int j = 0;

	prt_f prt_fun[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hex}, {'X', print_HEX},
		{'\0', NULL}
	};

	(*i)++;

	if (!fmt[*i])
		return(-1);

	while (prt_fun[j].c)
	{
		if (fmt[*i] == prt_fun[j].c)
			return (prt_fun[j].func_ptr(args, buffer, ibuf));
		j++;
	}

	handl_buf(buffer, '%', ibuf);
	handl_buf(buffer, fmt[*i], ibuf);
	return (2);
}

