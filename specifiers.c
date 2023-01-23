#include "main.h"
#include <unistd.h>

/**
 * to_binary - converts an integer to binary
 *
 * @arg: argument pointer to int to be converted
 * Return: On success 0
 */
int to_binary(va_list arg)
{
	int i = 0, j, n, binary_num[32];
	char c;

	n = va_arg(arg, int);
	while (n > 0)
	{
		binary_num[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		c = binary_num[j] + '0';
		_putchar(c);
	}
	return (0);
}

/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @arg: argument pointer to integer
 * Return: On success 0
 */
int print_unsigned_int(va_list arg)
{
	int i, n, temp, digit, digits = 0, divisor = 1;
	char digit_char;

	n = va_arg(arg, int);
	if (n < 0)
		n = -n;

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
 * print_unsigned_oct - represents an integer in unsigned octal
 *
 * @arg: argument pointer to inetger
 * Return: On success 0
 */
int print_unsigned_oct(va_list arg)
{
	char oct_num[100];
	unsigned int i = 0, num;

	num = va_arg(arg, int);

	do {
		oct_num[i++] = (num % 8) + '0';
		num /= 8;
	} while (num);

	while (i--)
		_putchar(oct_num[i]);
	return (0);
}

/**
 * hex_lower - represents an integer in unsigned hexadecimal (lowercase)
 *
 * @arg: argument pointer to inetger
 * Return: On success 0
 */
int hex_lower(va_list arg)
{
	int i;
	unsigned int n = va_arg(arg, int);
	char hex_digits[] = "0123456789abcdef";
	char hex_str[sizeof(unsigned int) * 2 + 1];

	for (i = sizeof(unsigned int) * 2 - 1; i >= 0; i--)
	{
		hex_str[i] = hex_digits[n & 0xF];
		n >>= 4;
	}
	hex_str[sizeof(unsigned int) * 2] = '\0';

	write(1, hex_str, sizeof(unsigned int) * 2);
	return (0);
}

/**
 * hex_UPPER - represents an integer in unsigned hexadecimal (uppercase)
 *
 * @arg: argument pointer to inetger
 * Return: On success 0
 */
int hex_UPPER(va_list arg)
{
	int i;
	unsigned int n = va_arg(arg, int);
	char hex_digits[] = "0123456789ABCDEF";
	char hex_str[sizeof(unsigned int) * 2 + 1];

	for (i = sizeof(unsigned int) * 2 - 1; i >= 0; i--)
	{
		hex_str[i] = hex_digits[n & 0xF];
		n >>= 4;
	}
	hex_str[sizeof(unsigned int) * 2] = '\0';

	write(1, hex_str, sizeof(unsigned int) * 2);
	return (0);
}
