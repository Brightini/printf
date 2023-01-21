#include "main.h"

/**
 * print_number - prints an integer
 *
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int x;

	x = n;
	if (n < 0)
	{
		_putchar('-');
		x = -(n);
	}
	if (x / 10)
		print_number(x / 10);
	_putchar(x % 10 + '0');
}

/**
 * _puts - prints a string to stdout
 *
 * @str: pointer to string
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}

/**
 * _printf - formats and prints data
 *
 * @format: a character string
 * Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	int i, char_count = 0;
	va_list args; /* argument pointer */

	/* initialises args by passing the address of @format */
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			/* format(++i) to check if the char next to */
			/* '%' matches any of the cases. */
			switch (format[++i])
			{
				case 'd':
				case 'i':
					print_number(va_arg(args, int));
					i++;
					break;
				case 'c':
					_putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					_puts(va_arg(args, char *));
					i++;
					break;
				case '%': /* for a situation like _printf("%%") */
					break; /* out of the switch statement to print '%' only */
				default: /* for a situation like _printf("%r") */
					_putchar(format[i - 1]); /* to print '%r' */
			}
		}
		_putchar(format[i]);
		++char_count; /* counts each character printed from @format */
	}
	va_end(args); /* free args of its list and all memory allocated */
	return (char_count);
}
