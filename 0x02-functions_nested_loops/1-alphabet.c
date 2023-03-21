#include "main.h"

/**
 * print_alphabet - Print alphabet in lowercase
 * followed by a new line
 */

void print_alphabet(void)
{
	int first_lower_char = (int)'a';
	int last_lower_char = (int)'z';

	while (first_lower_char <= last_lower_char)
	{
		_putchar(first_lower_char);
		first_lower_char++;
	}
	_putchar('\n');
}

