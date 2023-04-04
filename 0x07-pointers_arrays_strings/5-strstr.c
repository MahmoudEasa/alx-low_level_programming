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
	char *first_pos;
	int found, first_found = 0;

	while (*needle)
	{
		while (*haystack)
		{
			found = 0;
			if (*needle == *haystack)
			{
				if (first_found == 0)
				{
					first_found = 1;
					first_pos = haystack;
					found = 1;
					break;
				}
				else
				{
					found = 1;
					break;
				}
			}
			haystack++;
		}
		if (found == 0 && first_found)
			break;
		needle++;
	}

	if (*needle != '\0')
		return (NULL);

	return (first_pos);
}

