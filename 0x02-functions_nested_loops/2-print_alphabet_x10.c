#include "main.h"

/**
 * print_alphabet_x10 - Print 10 times the alphabet,
 * In lowercase, followed by a new line
 */

void print_alphabet_x10(void)
{
	int first_lower, i;

	for (i = 0; i < 10; i++)
	{
		for (first_lower = (int)'a'; first_lower <= (int)'z'; first_lower++)
			_putchar(first_lower);
		_putchar('\n');
	}

}

