#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 *	there is one or more chars in the string b that is not 0 or 1
 *	b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0, binary = 1;
	int len, i;

	if (!b || *b == '\0')
		return (0);

	len = strlen(b);
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		if (b[i] == '1')
			num += binary;

		binary += binary;
	}

	return (num);
}

