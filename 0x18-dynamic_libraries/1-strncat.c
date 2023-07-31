#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n:	number of strings to concatenate
 *
 * Return: pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int src_len = _strlen(src);

	if (src_len == 0)
	{
		return (dest);
	}
	else
	{
		int i, dest_len = _strlen(dest);

		if (n >= src_len)
		{
			for (i = 0; i <= src_len; i++)
			{
				dest[dest_len] = src[i];
				dest_len++;
			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				dest[dest_len] = src[i];
				dest_len++;
			}

			dest[dest_len] = '\0';
		}
	}

	return (dest);
}

