#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
* print_char - prints a character
* @args: va_list containing the character to print
* @buffer: buffer to store the character
* @ibuf: pointer to the current index in the buffer
* Return: number of characters printed
*/
int print_char(va_list *args, char buffer[], int *ibuf)
{
	char c = (char)(va_arg(*args, int));

	handl_buf(buffer, c, ibuf);
	return (1);
}
/**
* print_str - prints a string
* @args: va_list containing the string to print
* @buffer: buffer to store the string
* @ibuf: pointer to the current index in the buffer
* Return: number of characters printed
*/
int print_str(va_list *args, char buffer[], int *ibuf)
{
	int i;

	char *s = va_arg(*args, char *);

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		handl_buf(buffer, s[i], ibuf);

	return (i);
}
/**
* print_per - prints a percent sign
* @args: va_list (not used)
* @buffer: buffer to store the percent sign
* @ibuf: pointer to the current index in the buffer
* Return: number of characters printed
*/
int print_per(va_list *args, char buffer[], int *ibuf)
{
	(void)*args;
	handl_buf(buffer, '%', ibuf);
	return (1);
}

/**
* print_int - prints an integer
* @args: va_list containing the integer to print
* @buffer: buffer to store the integer
* @ibuf: pointer to the current index in the buffer
* Return: number of characters printed
*/
int print_int(va_list *args, char buffer[], int *ibuf)
{
	long int n;

	unsigned long int tmp1, tmp2 = 1, len = 0;

	char nump;

	n = va_arg(*args, int);

	if (n < 0)
	{
		handl_buf(buffer, '-', ibuf);
		len++;
		tmp1 = -n;
	}
	else if (n == 0)
	{
		handl_buf(buffer, '0', ibuf);
		return (1);
	}
	else
		tmp1 = n;
	while (tmp1 / tmp2 > 9)
		tmp2 *= 10;
	while (tmp2)
	{
		nump = (tmp1 / tmp2) + '0';
		handl_buf(buffer, nump, ibuf);
		len++;
		tmp1 %= tmp2;
		tmp2 /= 10;
	}
	return (len);
}

/**
* print_binary - prints an unsigned integer in binary
* @args: va_list containing the unsigned integer to print
* @buffer: buffer to store the binary representation
* @ibuf: pointer to the current index in the buffer
* Return: number of characters printed
*/
int print_binary(va_list *args, char buffer[], int *ibuf)
{
	unsigned int n, m, i, sum, a[32];

	int count = 0;

	char z;

	n = va_arg(*args, unsigned int);

	m = 2147483648; /* 2^31 */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			z = '0' + a[i];
			handl_buf(buffer, z, ibuf);
			count++;
		}
	}
	return (count);
}
