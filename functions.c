#include "main.h"

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

	/*putting each character in malloced space*/
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
	for (k = j - 1; k >= 0; k--)/*minus 1 from j because j = i */
		_putchar(ptr[k]);
	free(ptr);
	return (i);
}
