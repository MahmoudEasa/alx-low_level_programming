#include <string.h>

/**
 * _memset - fills memory with a constant byte
 * @s: buffer
 * @b: character
 * @n: size to fill
 *
 * Return: pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*(s + i) = b;
		i++;
	}
	return (s);
}

