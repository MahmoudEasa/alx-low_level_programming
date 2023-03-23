#include "main.h"

/**
 * print_square - print a square, followed by a new line
 * @size: the size of the square
 */

void print_square(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar(10);
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			_putchar('#');
		_putchar(10);
	}
}

