#include "main.h"

/**
 * print_last_digit - print the last digit of a number
 * @n: number
 *
 * Return: last digit of n
 */

int print_last_digit(int n)
{
	int last_digit = (n % 10);

	if (n >= 0)
	{
		_putchar('0' + last_digit);
		return (last_digit);
	}
	else
	{
		_putchar('0' + -(last_digit));
		return (-(last_digit));
	}
}

