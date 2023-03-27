#include "main.h"

/**
 * rev_string - reverse a string
 * @s: string
 */

void rev_string(char *s)
{
	int i = 0;
	int length = _strlen(s) - 1;

	while (i < length)
	{
		swap_char(s + length, s + i);
		i++;
		length--;
	}
}

/**
 * _strlen - return the length of a string
 * @s: (char) Pointer of string
 *
 * Return: Length of s
 */

int _strlen(char *s)
{
	int len;
	char *ptr = s;

	while (*ptr != '\0')
	{
		len++;
		ptr++;
	}

	return (len);
}

/**
 * swap_char - swap to characters
 * @a: first character
 * @b: second character
 */

void swap_char(char *a, char *b)
{
	char temp = *a;

	*a = *b;
	*b = temp;
}

