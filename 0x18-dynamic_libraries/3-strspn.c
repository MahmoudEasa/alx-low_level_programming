#include <string.h>
#include <stdio.h>

/**
 * _strspn - gets the length of a prefix substring.
 * @s: String 1
 * @accept: String 2
 *
 * Return: number of bytes in the initial segment of s
 *	which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0, found;
	char *accept_ptr = accept;
	char *str = s;

	while (*str)
	{
		found = 0;
		while (*accept_ptr)
		{
			if (*accept_ptr == *str)
			{
				count++;
				found = 1;
				break;
			}
			accept_ptr++;
		}
		str++;
		accept_ptr = accept;

		if (found == 0)
			break;
	}
	return (count);
}

