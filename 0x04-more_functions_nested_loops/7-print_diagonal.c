#include "main.h"

/**
 * print_diagonal - draw a diagonal line on the terminal
 * @n: the number of times the character \ should be printed
 *	If n is 0 or less, the function should only print a \n
 */

void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar(10);
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			_putchar(' ');
			if (j == i)
				_putchar('\\');
		}
		_putchar(10);
	}
}

