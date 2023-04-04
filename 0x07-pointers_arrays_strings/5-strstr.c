#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: First String
 * @needle: Second String
 *
 * Return: pointer to the beginning of the located substring,
 *	or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if (*needle == *haystack)
			return (haystack);
		haystack++;
	}
	return (NULL);
}

