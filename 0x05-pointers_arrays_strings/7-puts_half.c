#include "main.h"

/**
 * puts_half - print half of a string, followed by a new line
 * @str: (char) Pointer of string
 */

void puts_half(char *str)
{
	int i = 0, len = 0, n;

	while (str[i++] != '\0')
		len++;

	if (len % 2 != 0)
		n = ((len - 1) / 2) + 1;
	else
		n = len / 2;

	for (i = n; i < len; i++)
		_putchar(str[i]);

	_putchar(10);
}

