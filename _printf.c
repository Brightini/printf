#include "main.h"

/**
 * _printf - formats and prints data
 *
 * @format: a character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, char_count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	for (; format[i] != '\0'; i++)
	{
		/* for nomal characters */
		if (format[i] != '%')
			char_count += _putchar(format[i]);

		if (format[i] == '%')
		{
			/* for a case like '%%' */
			if (format[++i] == '%')
				char_count += _putchar('%');
			else
				match_spec(format[i], args);
		}
	}
	va_end(args);
	return (char_count);
}
