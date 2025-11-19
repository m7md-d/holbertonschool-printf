#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 * Return: number of characters printed
 */
int print_char(va_list *args)
{
	char c = (char)(va_arg(*args, int));

	return (write(1, &c, 1));
}
/**
 * print_str - prints a string
 * @args: va_list containing the string to print
 * Return: number of characters printed
 */
int print_str(va_list *args)
{
	int i;

	char *s = va_arg(*args, char *);

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		;

	return (write(1, s, i));
}
/**
 * print_per - prints a percent sign
 * @args: va_list (not used)
 * Return: number of characters printed
 */
int print_per(va_list *args)
{
	char p = '%';

	(void)*args;

	return (write(1, &p, 1));
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list *args)
{
	long int n;

	unsigned long int tmp1, tmp2 = 1, len = 0;

	char nump;

	n = va_arg(*args, int);

	if (n < 0)
	{
		len += write(1, "-", 1);
		tmp1 = -n;
	}
	else if (n == 0)
	{
		return (write(1, "0", 1));
	}

	else
		tmp1 = n;
	while (tmp1 / tmp2 > 9)
		tmp2 *= 10;
	while (tmp2)
	{
		nump = (tmp1 / tmp2) + '0';
		len += write(1, &nump, 1);
		tmp1 %= tmp2;
		tmp2 /= 10;
	}
	return (len);
}
