#include "main.h"
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	char *putchar = "_putchar";
	char *ptr = putchar;
	int i;
	int size = strlen(putchar);

	for (i = 0; i < size; i++)
	{
		_putchar(*ptr);
		ptr++;
	}
	_putchar('\n');
	return (0);
}

