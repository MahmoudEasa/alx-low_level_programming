#include <stddef.h>
#include <stdio.h>

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
	char *h = haystack;
	char *n = needle;
	char *current_h, *current_n;

	if (*n == '\0')
		return (haystack);

	if (*h == '\0')
		return (NULL);

	while (*h != '\0')
	{
		current_h = h;
		current_n = n;

		while (*current_h == *current_n)
		{
			if (*current_n == '\0')
				return (h);
			current_h++;
			current_n++;
		}
		h++;
	}
	return (NULL);
}

