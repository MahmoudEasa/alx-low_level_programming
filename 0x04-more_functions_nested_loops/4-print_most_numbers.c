#include "main.h"

/**
 * print_most_numbers - print the numbers, from 0 to 9, followed by a new line
 * Do not print 2 and 4
 */

void print_most_numbers(void)
{
	int i;

	for (i = (int)'0'; i <= (int)'9'; i++)
	{
		if (i == (int)'2' || i == (int)'4')
			continue;
		_putchar((char)i);
	}
	_putchar('\n');
}

