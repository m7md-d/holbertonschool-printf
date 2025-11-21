#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - Prints an unsigned number (Your Logic)
 * @args: List of arguments
 * @buffer: Buffer array
 * @ibuf: Buffer index
 * Return: Number of chars printed
 */
int print_unsigned(va_list *args, char buffer[], int *ibuf)
{
	unsigned int n = va_arg(*args, unsigned int), tmp, div = 1;
	int len = 0;

	tmp = n;
	while (tmp / div > 9)
		div *= 10;

	while (div != 0)
	{
		len++;
		handl_buf(buffer, ((tmp / div) % 10) + '0', ibuf);
		div /= 10;
	}
	return (len);
}

/**
 * print_octal - Prints octal number (Your Logic)
 * @args: List of arguments
 * @buffer: Buffer array
 * @ibuf: Buffer index
 * Return: Number of chars printed
 */
int print_octal(va_list *args, char buffer[], int *ibuf)
{
	unsigned int n = va_arg(*args, unsigned int), tmp, div = 1;
	int len = 0;

	tmp = n;
	while (tmp / div > 7)
		div *= 8;

	while (div != 0)
	{
		len++;
		handl_buf(buffer, ((tmp / div) % 8) + '0', ibuf);
		div /= 8;
	}
	return (len);
}

/**
 * print_hex - Prints hex number (Array Logic - Easier for Hex)
 * @args: List of arguments
 * @buffer: Buffer array
 * @ibuf: Buffer index
 * Return: Number of chars printed
 */
int print_hex(va_list *args, char buffer[], int *ibuf)
{
	unsigned int n = va_arg(*args, unsigned int);
	char temp[32], map[] = "0123456789abcdef";
	int i = 0, j;

	if (n == 0)
	{
		handl_buf(buffer, '0', ibuf);
		return (1);
	}

	while (n > 0)
	{
		temp[i++] = map[n % 16];
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		handl_buf(buffer, temp[j], ibuf);

	return (i);
}

/**
 * print_HEX - Prints HEX number (Array Logic - Easier for Hex)
 * @args: List of arguments
 * @buffer: Buffer array
 * @ibuf: Buffer index
 * Return: Number of chars printed
 */
int print_HEX(va_list *args, char buffer[], int *ibuf)
{
	unsigned int n = va_arg(*args, unsigned int);
	char temp[32], map[] = "0123456789ABCDEF";
	int i = 0, j;

	if (n == 0)
	{
		handl_buf(buffer, '0', ibuf);
		return (1);
	}

	while (n > 0)
	{
		temp[i++] = map[n % 16];
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		handl_buf(buffer, temp[j], ibuf);

	return (i);
}
