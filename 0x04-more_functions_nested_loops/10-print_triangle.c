#include "main.h"

/**
 * print_triangle - print a triangle, followed by a new line
 * @size: the size of the triangle
 *	If size is 0 or less, the function should print only a new line
 */

void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar(10);
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size - 1; j++)
			_putchar(' ');

		for (k = 0; k <= i; k++)
			_putchar('#');

		_putchar(10);
	}
}

