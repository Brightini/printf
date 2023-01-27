#include "main.h"
#include <stdint.h>

/**
 * print_hex - prints an integer in unsigned hexadecimal
 *
 * @n: integer to be converted
 * @form: deteremines what case (lower or upper) in hex to be printed
 * Return: number of characters printed
*/
int print_hex(unsigned int n, int form)
{
	long int i = 0, j = 0, k, remainder;
	unsigned int val;
	char *ptr;

	val = n;
	if (n == 0)
		return (_putchar('0'));
	/* to get length of output */
	for (; val > 0; i++)
		val /= 16;

	/* malloc space to keep remainder */
	ptr = malloc(sizeof(char) * i);
	if (ptr == NULL)
		return (-1);

	/*putting each character in malloc'ed space*/
	for (; j < i; j++)
	{
		remainder = n % 16;
		if (remainder < 10)
			ptr[j] = remainder + 48;
		else
			ptr[j] = remainder - 10 + form;
		n /= 16;
	}
	/* printing in reverse */
	for (k = j - 1; k >= 0; k--)/* -1 from j because j = i */
		_putchar(ptr[k]);
	free(ptr);
	return (i);
}

/**
 * print_address - prints address contained in a pointer
 *
 * @arg: argument pointer to address
 * Return: number of characters printed
*/
int print_address(va_list arg)
{
	int i = 0, k, char_count = 0, size, check = 0;
	uintptr_t add = (uintptr_t)va_arg(arg, void *);
	char *ptr;
	unsigned int remainder;

	if (!add)
		return (_puts("(nil)"));
	/* starts printing with these */
	char_count += _puts("0x");
	size = sizeof(uintptr_t) * 2;

	/* malloc space to keep remainder */
	ptr = malloc(size);
	if (ptr == NULL)
		return (-1);
	/*putting each character in malloc'ed space*/
	for (; i < size; i++)
	{
		remainder = add % 16;
		if (remainder < 10)
			ptr[i] = remainder + 48;
		else
			ptr[i] = remainder - 10 + 'a';
		add /= 16;
	}
	/* printing in reverse */
	for (k = i - 1; k >= 0; k--)/* -1 from i because i = size */
	{
		/* check is set to 1 to remove leading 0's */
		if (ptr[k] != '0' || check == 1)
		{
			char_count += _putchar(ptr[k]);
			if (ptr[k] != '0')
				check = 1;
			else
				check = check;
		}
	}
	free(ptr);
	return (char_count);
}
