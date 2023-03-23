#include "main.h"

/**
 * print_numbers - print the numbers, from 0 to 9, followed by a new line
 */

void print_numbers(void)
{
	int i;

	for (i = (int)'0'; i <= (int)'9'; i++)
		_putchar((char)i);
	_putchar('\n');
}

