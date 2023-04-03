#include <string.h>

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
	unsigned int i = 0, s_len = strlen(s);
	char *f = NULL;

	while (i < s_len)
	{
		if (c == *(s + i))
		{
			f = (s + i);
			break;
		}
		i++;
	}
	return (f);
}

