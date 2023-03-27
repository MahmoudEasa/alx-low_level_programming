#include "main.h"

/**
 * puts2 - print every other character of a string,
 * starting with the first character, followed by a new line
 * @str: (char) Pointer to string
 */

void puts2(char *str)
{
	int i = 0, len = 0;

	while (str[i++] != '\0')
		len++;

	for (i = 0; i < len; i += 2)
		_putchar(str[i]);

	_putchar(10);
}

