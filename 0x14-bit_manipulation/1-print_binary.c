#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */

void print_binary(unsigned long int n)
{
	int i, start_print = 0;

	if (n < 2)
	{
		_putchar((n + '0'));
		return;
	}

	for (i = 31; i >= 0; i--)
	{
		if (((n >> i) & 1) == 1 || start_print == 1)
		{
			start_print = 1;
			_putchar(((n >> i) & 1) + '0');
		}
	}

}

