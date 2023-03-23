#include "main.h"

/**
 * print_line - draw a straight line in the terminal
 * @n: the number of times the character _ should be printed
 *	If n is 0 or less, the function should only print \n
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar(10);
		return;
	}

	for (i = 0; i < n; i++)
		_putchar('_');
	_putchar(10);
}

