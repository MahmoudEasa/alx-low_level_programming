#include "main.h"
#include <stdio.h>

int _strlen(char *s);

/**
 * rev_string - reverse a string
 * @s: string
 */

void rev_string(char *s)
{
	int i, j = 0;
	int size = _strlen(s);
	char temp;

	for (i = size - 1; i >= 0; i--)
	{
		if (j < i)
		{
			temp = *(s + j);
			*(s + j) = *(s + i);
			*(s + i) = temp;
			j++;
		}
		else
			break;
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

