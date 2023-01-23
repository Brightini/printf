#include "main.h"

/**
 * match_spec - matches a specifier to its function
 *
 * @ch: specifier to be matched
 * @args: argument pointer that holds the value to be printed
 * Return: 0 if a specifier is found. Otherwise 1
*/
int match_spec(char ch, va_list args)
{
	int i = 0;

	cf_t match[] = {
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"c", print_char},
		{"b", to_binary},
		{"u", print_unsigned_int},
		{"o", print_unsigned_oct},
		{"x", hex_lower},
		{"X", hex_UPPER},
		{NULL, NULL},
	};

	for (; match[i].c; i++)
	{
		if (ch == *(match[i].c))
		{
			match[i].ptr(args);
			return (0);
		}
	}
	return (1);
}
