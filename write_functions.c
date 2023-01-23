#include "main.h"
#include <unistd.h>

/**
 * print_string - prints a string to stdout
 *
 * @str: argument pointer to string
 * Return: On success 0
 */
int print_string(va_list str)
{
	int i;
	char *temp = va_arg(str, char *);

	for (i = 0; temp[i] != '\0'; i++)
		_putchar(temp[i]);
	return (0);
}

/**
 * print_int - prints an integer
 *
 * @arg: argument pointer to integer to be printed
 * Return: On success 0
 */
int print_int(va_list arg)
{
	int i, n, temp, digit, digits = 0, divisor = 1;
	char digit_char;

	n = va_arg(arg, int);
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	temp = n;
	while (temp)
	{
		temp /= 10;
		digits++;
	}
	for (i = 1; i < digits; i++)
		divisor *= 10;
	for (i = digits - 1; i >= 0; i--)
	{
		digit = n / divisor;
		digit_char = digit + '0';
		_putchar(digit_char);
		n %= divisor;
		divisor /= 10;
	}
	return (0);
}

/**
 * print_char - writes the character c to stdout
 * @c: argment pointer to the character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list c)
{
	char ch = va_arg(c, int);

	return (write(1, &ch, 1));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
