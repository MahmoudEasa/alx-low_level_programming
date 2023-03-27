#include "main.h"

/**
 * print_rev - print a string, in reverse, followed by a new line
 * @s: string
 */

void print_rev(char *s)
{
	int i;
	int size = 0;
	char *ptr = s;

	while (*ptr != '\0')
	{
		size++;
		ptr++;
	}

	ptr = s;

	for (i = size; i >= 0; i--)
		_putchar(*(ptr + i));

	_putchar(10);
}

