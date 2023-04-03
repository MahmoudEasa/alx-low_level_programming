#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: charcter
 *
 * Return: pointer to the first occurrence of the character c
 *	in the string s, or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (*(s + i) != '\0')
	{
		if (c == *(s + i))
		{
			return (s + i);
		}

		i++;
	}
	return (NULL);
}

