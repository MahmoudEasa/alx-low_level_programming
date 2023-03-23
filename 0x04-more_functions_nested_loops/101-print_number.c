#include "main.h"

/**
 * print_number - print an integer
 * @n: integer
 */

void print_number(int n)
{
	int one, ten, hundred;

	if (n == 0)
	{
		_putchar('0');
	}
	else if (n < 0)
	{
		_putchar('-');
		_putchar(-(n / 10) + '0');
		_putchar(-(n % 10) + '0');
	}
	else if (n < 100)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}
	else if (n < 1000)
	{
		one = n / 100;
		ten = n / 10;

		_putchar((one) + '0');
		_putchar((ten % 10) + '0');
		_putchar((n % 10) + '0');
	}
	else
	{
		one = n / 1000;
		ten = n / 100;
		hundred = n % 100;

		_putchar((one) + '0');
		_putchar((ten % 10) + '0');
		_putchar((hundred / 10) + '0');
		_putchar((n % 10) + '0');
	}
}

