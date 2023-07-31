#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: String 1
 * @accept: String 2
 *
 * Return: pointer to the byte in s that matches one of the bytes in accept,
 *	or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	char *accept_ptr = accept;

	while (*s)
	{
		while (*accept_ptr)
		{
			if (*s == *accept_ptr)
				return (s);
			accept_ptr++;
		}
		accept_ptr = accept;

		s++;
	}
	return (NULL);
}

